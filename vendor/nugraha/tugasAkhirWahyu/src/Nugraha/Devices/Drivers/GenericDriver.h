namespace Nugraha { namespace Devices { namespace Drivers { 

class GenericDriver: public Driver 
{
protected:
    
public:
    GenericDriver()
    {
        
    }
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