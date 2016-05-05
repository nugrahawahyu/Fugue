namespace Nugraha { namespace TugasAkhirWahyu { namespace Sensors {
using Nugraha::TugasAkhirWahyu::Contracts::Sensors::DriverContract;

class Driver : public DriverContract 
{
protected:
    
public:
    virtual void readMeasurementValue(int pin);
};

}}}