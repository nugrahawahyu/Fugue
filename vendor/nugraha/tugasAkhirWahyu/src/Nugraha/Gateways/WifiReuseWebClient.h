namespace Nugraha { namespace Devices {

class WifiReuseWebClient : public virtual Gateway
{
protected:
    ESP8266WiFiMulti WiFiMulti;
    HTTPClient http;
    long interval = 1000;
    unsigned long previousMillis = 0;

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

        WiFiMulti.addAP("SSID", "PASSWORD");

        // allow reuse (if server supports it)
        http.setReuse(true);
    }

    void runService()
    {
        unsigned long currentMillis = millis();
        if(currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;

            // wait for WiFi connection
            if((WiFiMulti.run() == WL_CONNECTED)) {

                http.begin("http://192.168.1.12/test.html");
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
    }
};

}}