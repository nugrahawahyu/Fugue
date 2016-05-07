namespace Nugraha { namespace TugasAkhirWahyu { namespace Sensors {
using Nugraha::TugasAkhirWahyu::Contracts::Sensors::SensorContract;

class Sensor : public SensorContract 
{
protected:
    Driver* driver;

public:
    int id;
    int pin;
    const char* name;

    Sensor(int pin, const char* name)    {
        this->pin = pin;
        this->name = name;
        this->driver = new GenericDriver();
    }

    /**
     * Mendapatkan hasil pembacaan sensor.
     *
     * @return int
     */
    virtual double readMeasurementValue();
};

}}}