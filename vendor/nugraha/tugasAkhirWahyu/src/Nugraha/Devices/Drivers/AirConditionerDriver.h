namespace Nugraha { namespace Devices { namespace Drivers { 

class AirConditionerDriver: public virtual Driver 
{
protected:
    
public:
    bool turnOn(int pin)
    {
        digitalWrite(pin, LOW);
        delay(1000);
        digitalWrite(pin, HIGH);
        return true;
    }
    bool turnOff(int pin)
    {
        digitalWrite(pin, LOW);
        delay(1000);
        digitalWrite(pin, HIGH);
        return true;
    }
};

}}}