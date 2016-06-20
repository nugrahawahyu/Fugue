namespace Nugraha { namespace Drivers { namespace Devices {
using Nugraha::Support::Facades::Scheduler::Scheduler;

class AirConditionerDriver: public virtual Driver 
{
protected:
    
public:
    bool turnOn(int pin)
    {
        digitalWrite(pin, HIGH);
        Scheduler::after(50, [=]() {
            digitalWrite(pin, LOW);
        });
        return true;
    }
    bool turnOff(int pin)
    {
        digitalWrite(pin, HIGH);
        Scheduler::after(50, [=]() {
            digitalWrite(pin, LOW);
        });
        return true;
    }
};

}}}