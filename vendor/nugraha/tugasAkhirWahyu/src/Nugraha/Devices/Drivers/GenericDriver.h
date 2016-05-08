namespace Nugraha { namespace Devices { namespace Drivers { 

class GenericDriver: public virtual Driver 
{
protected:
    
public:
    bool turnOn(int pin)
    {
        digitalWrite(pin, HIGH);
    }
    bool turnOff(int pin)
    {
        digitalWrite(pin, LOW);
    }
};

}}}