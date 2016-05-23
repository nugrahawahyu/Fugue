namespace App { namespace Gateways { namespace HttpClients {
using Nugraha::Gateways::Esp8266::WifiHttpClient;

class PersistentHttp : public virtual WifiHttpClient
{
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
        Scheduler::every(interval, this, &PersistentHttp::httpGet);
    }
};

}}}