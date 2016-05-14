using Nugraha::Support::Facades::Scheduler::Scheduler;

void ayam()
{
    Serial.println("Hello from Kambing!");
}

namespace Tests { namespace TestCases { 
using App::Boards::Arduino;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;
using Nugraha::Support::Facades::Scheduler::Scheduler;

class SchedulerTest;

class SchedulerTest : public virtual BaseController
{
public:
    void setup() 
    {
        Serial.println(F("### SCHEDULER TEST ###"));
        Scheduler::every(2000, ayam);
    }

    void loop() 
    {
        Scheduler::update();
    }
};

}}

