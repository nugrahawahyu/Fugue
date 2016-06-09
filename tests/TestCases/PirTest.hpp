namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Logger;
using Nugraha::Foundation::BaseController;

class PirTest : public virtual BaseController
{
protected:

public:
    void setup(void) 
    {
        Scheduler::every(500, [=]() {
            int val = digitalRead(D7);
            Serial.println(val);
        });
    }

    void loop() 
    {
        Scheduler::handleEvents();
    }
};

}}