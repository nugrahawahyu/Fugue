namespace Nugraha { namespace Devices {
using Nugraha::Traits::HasLogger;
using Nugraha::Support::Facades::Debug;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Devices::DriverContract;
using Nugraha::Contracts::Devices::DeviceContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class Device : public virtual DeviceContract, public HasLogger
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
                logger->addNotification(1, String(this->pin));
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
                logger->addNotification(0, String(this->pin));
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

    void setDriver(DriverContract* driver)
    {
        this->driver = driver;
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