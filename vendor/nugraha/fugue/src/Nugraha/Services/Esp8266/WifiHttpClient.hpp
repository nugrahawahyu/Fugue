namespace Nugraha { namespace Services { namespace Esp8266 {
using Nugraha::Traits::HasId;
using Nugraha::Traits::HasLogger;
using Nugraha::Contracts::Services::ServiceContract;
using Nugraha::Contracts::Foundation::BoardContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class WifiHttpClient : public virtual ServiceContract, public HasLogger, public HasId<int>
{
protected:
    ESP8266WiFiMulti WiFiMulti;
    HTTPClient http;
    BoardContract* board;

    String ssid            = env::wifi::ssid;
    String password        = env::wifi::password;
    unsigned long interval = 1000;

    String host;
    String mode;
    String publishKey;
    String subscribeKey;
    String signature;
    String channelName;
    String callback;
    String message = "{\"text\":\"hello\"}";
    String response;

public:
    WifiHttpClient(std::map<String, String> setting)
    {
        this->host = setting["host"];
        this->mode = setting["mode"];
        this->publishKey = setting["publishKey"];
        this->subscribeKey = setting["subscribeKey"];
        this->signature = setting["signature"];
        this->channelName = setting["channelName"];
        this->callback = setting["callback"];
        initialize();
    }

    virtual ~WifiHttpClient() {}
    
    void initialize()
    {
        Serial.println();
        Serial.println();
        Serial.println();

        for(uint8_t t = 4; t > 0; t--) {
            Serial.printf("[SETUP] WAIT %d...\n", t);
            Serial.flush();
            delay(1000);
        }

        char ssidCharArray[ssid.length()+1];
        ssid.toCharArray(ssidCharArray, ssid.length()+1);
        char passwordCharArray[password.length()+1];
        password.toCharArray(passwordCharArray, password.length()+1);
        WiFiMulti.addAP(ssidCharArray, passwordCharArray);
    }

    String generateUri()
    {
        if(message != "") {
            String uri = "http://" + host + "/" + mode + "/" + publishKey + "/" + subscribeKey + "/" + signature + "/" + channelName + "/" + callback + "/" + message;
            Serial.println(uri);
            return uri;
        }
    }

    template<typename Callback>
    void httpGet(String uri, Callback callback)
    {
        // wait for WiFi connection
        if((WiFiMulti.run() == WL_CONNECTED)) {
            unsigned long tempMillis = millis();
            http.begin(uri);
            // http.begin("192.168.1.12", 80, "/test.html");

            int httpCode = http.GET();
            if(httpCode > 0) {
                Serial.printf("[HTTP] GET... code: %d\n", httpCode);

                // file found at server
                if(httpCode == HTTP_CODE_OK) {
                    // Hitung delay.
                    addDelayToRecord(String(millis() - tempMillis));
                    // Ekstrak pesan dan panggil fungsi callback.
                    response = http.getString();
                    callback();
                } else {
                    addDelayToRecord(String(0));
                }
            } else {
                Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
            }

            http.end();
        }
    }

    int getId() override {HasId::getId();}

    void updateMessage()
    {
        if(logger != NULL) {
            this->message = logger->getLogMessage();
        }
    }
    
    void setLogger(LoggerContract* logger) override
    {
        HasLogger::setLogger(logger);
        addDelayToRecord(String(0));
    }

    LoggerContract* getLogger()
    {
        return logger;
    }

    void setBoard(BoardContract* board)
    {
        this->board = board;
    }

    void addDelayToRecord(String value)
    {
        getLogger()->addConnectionInfo("delay", value);
    }
};

}}}