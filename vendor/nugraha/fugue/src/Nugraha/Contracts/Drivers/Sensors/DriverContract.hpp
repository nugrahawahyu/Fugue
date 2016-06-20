namespace Nugraha { namespace Contracts { namespace Drivers { namespace Sensors {

class DriverContract 
{
public:
    virtual ~DriverContract() {}
    virtual double readMeasurementValue(int pin)=0;
};

}}}}