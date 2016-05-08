namespace Nugraha { namespace Sensors {
using Nugraha::Sensors::Drivers::Driver;
using Nugraha::Sensors::Drivers::GenericDriver;
using Nugraha::Contracts::Sensors::SensorContract;

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

}}