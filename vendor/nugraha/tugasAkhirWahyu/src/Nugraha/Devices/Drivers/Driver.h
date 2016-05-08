namespace Nugraha { namespace Devices { namespace Drivers { 
using Nugraha::Contracts::Devices::DriverContract;

class Driver: public DriverContract 
{
protected:
    
public:
    virtual bool turnOn(int pin);
    virtual bool turnOff(int pin);
};

}}}