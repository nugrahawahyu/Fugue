namespace Nugraha { namespace Gateways { namespace Esp8266 {
using Nugraha::Traits::HasLogger;
using Nugraha::Contracts::Gateways::GatewayContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class WifiHttpClient : public virtual GatewayContract, public HasLogger
{
protected:
    ESP8266WiFiMulti WiFiMulti;
    HTTPClient http;
    
    String ssid            = env::wifi::ssid;
    String password        = env::wifi::password;
    unsigned long interval = 1000;

    // Uri settings.
    String hostIp       = env::httpClient::hostIp;
    String mode         = env::httpClient::mode;
    String publishKey   = env::httpClient::publishKey;
    String subscribeKey = env::httpClient::subscribeKey;
    String signature    = "0";
    String channelName  = "cartracker";
    String callback     = "0";
    String message      = "{\"text\":\"hello\"}";

public:
    String generateUri()
    {
        if(message != "") {
            String uri = "http://" + hostIp + "/" + mode + "/" + publishKey + "/" + subscribeKey + "/" + signature + "/" + channelName + "/" + callback + "/" + message;

            // Untuk memastikan pesan yang sama tidak terkirim lebih dari satu kali.
            message = "";

            return uri;
        }
    }

    void httpGet()
    {
        // wait for WiFi connection
        if((WiFiMulti.run() == WL_CONNECTED)) {
            http.begin(this->generateUri());
            //http.begin("192.168.1.12", 80, "/test.html");

            int httpCode = http.GET();
            if(httpCode > 0) {
                Serial.printf("[HTTP] GET... code: %d\n", httpCode);

                // file found at server
                if(httpCode == HTTP_CODE_OK) {
                    http.writeToStream(&Serial);
                }
            } else {
                Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
            }

            http.end();
        }
    }

    void setMessage(String message)
    {
        this->message = message;
    }
    
    void setLogger(LoggerContract* logger) override
    {
        HasLogger::setLogger(logger);
    }

    LoggerContract* getLogger() override
    {
        HasLogger::getLogger();
    }
};

}}}