namespace Nugraha { namespace Devices {
using Nugraha::Traits::HasId;
using Nugraha::Traits::HasLogger;
using Nugraha::Support::Facades::Debug;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Devices::DeviceContract;
using Nugraha::Contracts::Foundation::LoggerContract;
using Nugraha::Contracts::Drivers::Devices::DriverContract;

class Device : public virtual DeviceContract, public HasLogger, public HasId
{
protected:
    int pin = -1;
    bool isOn = false;
    SensorContract* sensor;
    DriverContract* driver;
    unsigned long previousMillis = 0;
    static DriverContract* defaultDriver;
    
public:
    Device(int pin, SensorContract* sensor)
    {
        this->pin = pin;
        this->sensor = sensor;
        this->driver = Device::defaultDriver;
    }
    
    virtual ~Device() {}

    /**
     * Jika perangkat sedang hidup maka matikan,
     * jika perangkat sedang mati maka hidupkan.
     */
    void toggle()
    {
        if (this->isOn==false) {
            this->turnOn();
        }
        else {
            this->turnOff();
        }
    }

    /**
     * Menghidupkan perangkat dan mengupdate state-nya.
     * @param  Device $device
     */
    void turnOn()
    {
        if(this->pin != -1) {
            if(driver->turnOn(this->pin)) {
                this->isOn = true;
                if(logger != NULL )
                    logger->addNotification(this->pin, true);
            }
        }
    }

    /**
     * Mematikan perangkat dan mengupdate state-nya.
     * @param  Device $device
     */
    void turnOff()
    {
        if(this->pin != -1) {
            if(driver->turnOff(this->pin)) {
                this->isOn = false;
                if(logger != NULL )
                    logger->addNotification(this->pin, false);
            }
        }
    }

    int getPin()
    {
        return this->pin;
    }

    void setSensor(SensorContract* sensor)
    {
        this->sensor = sensor;
    }

    SensorContract* getSensor()
    {
        return this->sensor;
    }

    void setDriver(DriverContract* driver)
    {
        this->driver = driver;
    }

    int getId() override {HasId::getId();}
    
    void setLogger(LoggerContract* logger) override {HasLogger::setLogger(logger);}

    LoggerContract* getLogger() override {HasLogger::getLogger();}
};

}}