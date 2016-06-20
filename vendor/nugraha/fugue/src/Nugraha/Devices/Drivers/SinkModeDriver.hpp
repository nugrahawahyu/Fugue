namespace Nugraha { namespace Devices { namespace Drivers { 

class SinkModeDriver : public virtual Driver 
{
protected:
    
public:
    bool turnOn(int pin)
    {
        digitalWrite(pin, LOW);
        return true;
    }
    bool turnOff(int pin)
    {
        digitalWrite(pin, HIGH);
        return true;
    }
};

}}}