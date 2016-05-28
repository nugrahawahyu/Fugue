namespace Nugraha { namespace Gateways { namespace Esp8266 {
using Nugraha::Traits::HasLogger;
using Nugraha::Contracts::Gateways::GatewayContract;
using Nugraha::Contracts::Foundation::BoardContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class WifiHttpClient : public virtual GatewayContract, public HasLogger
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
    }
    
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

        WiFiMulti.addAP("Fugue2", "fugue123");
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
            //http.begin("192.168.1.12", 80, "/test.html");

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
                    addDelayToRecord(String(-1));
                }
            } else {
                Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
            }

            http.end();
        }
    }

    void updateMessage()
    {
        this->message = getLogger()->getLogMessage();
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