namespace Nugraha { namespace Sensors {
using Nugraha::Traits::HasLogger;
using Nugraha::Sensors::Drivers::Driver;
using Nugraha::Sensors::Drivers::GenericDriver;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class Sensor : public virtual SensorContract, public HasLogger
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
    
    void setLogger(LoggerContract* logger) override
    {
        HasLogger::setLogger(logger);
    }

    LoggerContract* getLogger() override
    {
        HasLogger::getLogger();
    }
};

}}