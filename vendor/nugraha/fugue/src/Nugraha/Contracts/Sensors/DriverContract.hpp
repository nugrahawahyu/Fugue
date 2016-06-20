namespace Nugraha { namespace Contracts { namespace Sensors {

class DriverContract 
{
public:
    virtual ~DriverContract() {}
    virtual double readMeasurementValue(int pin)=0;
};

}}}