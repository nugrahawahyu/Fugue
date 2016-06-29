namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Logger;
using Nugraha::Foundation::BaseController;

class SignalStrengthTest : public virtual BaseController
{
protected:
    const char* SSID = "Fugue2";

    // Return RSSI or 0 if target SSID not found
    int32_t getRSSI(const char* target_ssid)
    {
        byte available_networks = WiFi.scanNetworks();

        for (int network = 0; network < available_networks; network++) {
            if (WiFi.SSID(network) == String(target_ssid)) {
                return WiFi.RSSI(network);
            }
        }
        return 0;
    }

public:

    void setup(void) 
    {

    }

    void loop() 
    {
        unsigned long before = millis();
        int32_t rssi = getRSSI(SSID);
        unsigned long after = millis();
        // Serial.print("Signal strength: ");
        Serial.println(rssi);
        // Serial.println("dBm");

        // Serial.print("Took ");
        // Serial.print(after - before);
        // Serial.println("ms");
        delay(1000);       
    }
};

}}