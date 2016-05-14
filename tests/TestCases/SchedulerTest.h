using Nugraha::Support::Facades::Scheduler::Scheduler;

void ayam()
{
    Serial.println("Hello from ayam!");
}

namespace Tests { namespace TestCases { 
using App::Boards::Arduino;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;
using Nugraha::Support::Facades::Scheduler::Scheduler;

class InduokAyam
{
public:
    void kokok()
    {
        Serial.println("Kukuruyuuuk...");
    } 
};

class SchedulerTest : public virtual BaseController
{
public:
    void setup() 
    {
        InduokAyam induokAyam;
        Serial.println(F("### SCHEDULER TEST ###"));
        Scheduler::every(800, this, &SchedulerTest::kambing);
        Scheduler::every(1337, &induokAyam, &InduokAyam::kokok);
        Scheduler::every(1650, ayam);
    }

    void loop()
    {
        Scheduler::update();
    }

    void kambing()
    {
        Serial.println("Hello from kambing!");
    }
};

}}

