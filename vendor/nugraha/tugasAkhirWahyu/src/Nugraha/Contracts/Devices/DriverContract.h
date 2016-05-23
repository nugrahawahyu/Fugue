namespace Nugraha { namespace Contracts { namespace Devices {

class DriverContract 
{
public:
    virtual bool turnOn(int pin)=0;
    virtual bool turnOff(int pin)=0; 
};

}}}