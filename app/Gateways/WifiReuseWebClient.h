namespace App { namespace Gateways {
using Nugraha::Gateways::WifiGateway;

class WifiReuseWebClient : public virtual WifiGateway
{
protected:
    ESP8266WiFiMulti WiFiMulti;
    HTTPClient http;
    unsigned long interval = 1000;

public:
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

        // allow reuse (if server supports it)
        http.setReuse(true);
    }

    void service()
    {
        Debug::println("Starting Wifi Reuse Web Client service...");
        Scheduler::every(interval, this, &WifiReuseWebClient::httpGet);
    }

    void httpGet()
    {
        // wait for WiFi connection
        if((WiFiMulti.run() == WL_CONNECTED)) {

            http.begin("http://54.249.82.173/publish/pub-c-3e5de365-5d57-48c7-a317-366ef2846eb4/sub-c-cca59b64-d972-11e5-bdd5-02ee2ddab7fe/0/cartracker/0/{\"text\":\"hello\"}");
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
};

}}