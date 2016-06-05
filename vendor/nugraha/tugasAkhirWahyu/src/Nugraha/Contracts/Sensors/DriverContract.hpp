namespace Nugraha { namespace Contracts { namespace Sensors {

class DriverContract 
{
public:
    virtual ~DriverContract() {}
    virtual void readMeasurementValue(int pin)=0;
};

}}}