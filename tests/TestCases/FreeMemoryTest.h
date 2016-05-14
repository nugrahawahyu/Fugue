namespace Tests { namespace TestCases { 
using App::Boards::Arduino;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;

class FreeMemoryTest : public virtual BaseController
{
public:
    void setup(void) 
    {
        Serial.begin(115200);
    }

    void loop() 
    {
        Serial.println("System ---");
        Serial.printf("getChipId: %08X\n", ESP.getChipId());
        Serial.printf("getCpuFreqMHz: %08d\n", ESP.getCpuFreqMHz());
        Serial.printf("getSdkVersion: %08X\n", ESP.getSdkVersion());
        Serial.printf("getBootVersion: %08X\n", ESP.getBootVersion());
        Serial.printf("getBootMode: %08X\n", ESP.getBootMode());
        Serial.printf("getCycleCount: %u\n", ESP.getCycleCount());
        
        Serial.println("Memory ---");
        Serial.printf("getFreeHeap: %08X\n", ESP.getFreeHeap());
        Serial.printf("getSketchSize: %u\n", ESP.getSketchSize());
        Serial.printf("getFreeSketchSpace: %u\n", ESP.getFreeSketchSpace());
    }
};

}}