namespace Nugraha { namespace Sensors {
using Nugraha::Contracts::Sensors::DriverContract;

class Driver : public DriverContract 
{
protected:
    
public:
    virtual void readMeasurementValue(int pin);
};

}}