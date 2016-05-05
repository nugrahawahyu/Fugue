namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices { 
using Nugraha::TugasAkhirWahyu::Contracts::Devices::DriverContract;

class Driver: public DriverContract 
{
protected:
    
public:
    virtual bool turnOn(int pin);
    virtual bool turnOff(int pin);
};

}}}