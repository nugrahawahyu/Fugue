namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Logger;
using Nugraha::Collections::Vector;
using Nugraha::Foundation::BaseController;

class SchedulerTest : public virtual BaseController
{
public:
    void setup() 
    {
        Serial.printf("getFreeHeap: %08d\n", ESP.getFreeHeap());

        Scheduler::every(1000, [=]() {
            ayam();
        });
    }

    void loop()
    {
        Scheduler::handleEvents();   
    }

    void ayam()
    {
        Serial.println("register new event.");
        Scheduler::after(500, [](){
            Serial.println("hallo");
        });
    }

};

}}

