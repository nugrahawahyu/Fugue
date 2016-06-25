namespace Nugraha { namespace Sensors {
using Nugraha::Traits::HasId;
using Nugraha::Traits::HasLogger;
using Nugraha::Drivers::Sensors::Driver;
using Nugraha::Traits::RecordableInstance;
using Nugraha::Drivers::Sensors::GenericDriver;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Foundation::LoggerContract;
using Nugraha::Contracts::Drivers::Sensors::DriverContract;

class Sensor : public virtual SensorContract, public HasLogger, public HasId<int>, public RecordableInstance<Sensor*>
{
protected:
    DriverContract* driver;

public:
    int id;
    int pin;
    
    Sensor(int pin)    {
        this->pin = pin;
        this->driver = new GenericDriver();
        myInstances.push_back(this);
    }

    virtual ~Sensor() {}

    int getId() override {HasId::getId();}

    void setLogger(LoggerContract* logger) override {HasLogger::setLogger(logger);}
    
    LoggerContract* getLogger() override {HasLogger::getLogger();}
};

}}