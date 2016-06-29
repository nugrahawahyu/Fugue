namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Logger;
using Nugraha::Collections::Vector;
using Nugraha::Foundation::BaseController;

const char* ssid     = "Fugue2";
const char* password = "fugue123";

class PingTest : public virtual BaseController
{
public:
    int pingCount=15;
    char* host = "www.wahyunugraha.com";
    void setup() 
    {
        delay(10);

        Serial.println();
        Serial.println("Sedang mencoba konek ke WiFi");
        if(!env::wifi::obtainIpAddressAutomatically) {
            WiFi.config(env::wifi::ip, env::wifi::gateway, env::wifi::subnet, env::wifi::dns1, env::wifi::dns2);
        }
        WiFi.begin(ssid, password);

        while (WiFi.status() != WL_CONNECTED) {
            delay(100);
            Serial.print(".");
        }

        Serial.println();
        Serial.print("WiFi konek dengan ip ");  
        Serial.println(WiFi.localIP());

        Scheduler::every(1000, [=]() {
            Serial.print("Pinging ");
            Serial.print(host);
            Serial.print(" delay = ");

            if(Ping.ping(host)) {
                Serial.print(Ping.averageTime());
                Serial.println(" ms");
            } else {
                Serial.println("timeout");
            }
        }, pingCount);
    }

    void loop() 
    {
        Scheduler::handleEvents();
    }

};

}}

