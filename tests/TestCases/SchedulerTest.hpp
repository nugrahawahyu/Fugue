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

        Scheduler::every((500), [=]() {
            ayam();
            // Serial.println("IKE DEYEN HAAAAA.........");
        });
    }

    void loop()
    {
        Scheduler::handleEvents();   
    }

    void ayam()
    {
        Serial.println("register new event.");
        Scheduler::after(499, [](){
            Serial.println("hallo");
        });
    }

};

}}

