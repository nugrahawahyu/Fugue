namespace Nugraha { namespace Devices {
using Nugraha::Support::Facades::Debug;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Devices::DriverContract;
using Nugraha::Contracts::Devices::DeviceContract;

class Device : public virtual DeviceContract
{
protected:
    SensorContract* sensor;
    DriverContract* driver;
    
public:
    int pin = -1;
    bool isOn = false;
    unsigned long previousMillis = 0;
    static DriverContract* defaultDriver;

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
            Debug::println("Hidupkan");
            this->turnOn();
        }
        else {
            Debug::println("Matikan");
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
            }
        }
    }

    void setSensor(SensorContract* sensor)
    {
        this->sensor = sensor;
    }

    void setDriver(DriverContract* driver)
    {
        this->driver = driver;
    }
};
}}