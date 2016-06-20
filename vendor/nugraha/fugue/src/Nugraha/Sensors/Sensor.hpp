namespace Nugraha { namespace Sensors {
using Nugraha::Traits::HasId;
using Nugraha::Traits::HasLogger;
using Nugraha::Sensors::Drivers::Driver;
using Nugraha::Sensors::Drivers::GenericDriver;
using Nugraha::Contracts::Sensors::DriverContract;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class Sensor : public virtual SensorContract, public HasLogger, public HasId
{
protected:
    DriverContract* driver;

public:
    int id;
    int pin;
    
    Sensor(int pin)    {
        this->pin = pin;
        this->driver = new GenericDriver();
    }

    virtual ~Sensor() {}

    int getId() override {HasId::getId();}

    void setLogger(LoggerContract* logger) override {HasLogger::setLogger(logger);}
    
    LoggerContract* getLogger() override {HasLogger::getLogger();}
};

}}