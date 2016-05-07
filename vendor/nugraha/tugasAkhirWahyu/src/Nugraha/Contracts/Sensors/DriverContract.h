namespace Nugraha { namespace Contracts { namespace Sensors {

class DriverContract 
{
public:
    virtual void readMeasurementValue(int pin)=0;
};

}}}