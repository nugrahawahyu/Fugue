namespace Nugraha { namespace Devices {
using Nugraha::Sensors::Sensor;
using Nugraha::Support::Facades::Debug;
using Nugraha::Devices::Drivers::Driver;
using Nugraha::Devices::Drivers::GenericDriver;
using Nugraha::Contracts::Devices::DeviceContract;

class Device : public virtual DeviceContract
{
protected:
    Sensor* sensor;
    Driver* driver;
    
public:
    int pin;
    bool isOn = false;
    unsigned long previousMillis = 0;
    static Driver* defaultDriver;

    Device(int pin, Sensor* sensor)
    {
        this->pin = pin;
        this->sensor = sensor;
        this->driver = Device::defaultDriver;
    }

    /**
     * Menghidupkan perangkat dan mengupdate state-nya.
     * @param  Device $device
     */
    void turnOn()
    {
        if(driver->turnOn(this->pin)) {
            this->isOn = true;
            // Debug::println("Berhasil Dihidupkan");
        }
    }

    /**
     * Mematikan perangkat dan mengupdate state-nya.
     * @param  Device $device
     */
    void turnOff()
    {
        if(driver->turnOff(this->pin)) {
            this->isOn = false;
            // Debug::println("Berhasil Dimatikan");
        }
    }

    void setSensor(Sensor* sensor)
    {
        this->sensor = sensor;
    }

    void setDriver(Driver* driver)
    {
        this->driver = driver;
    }
};
}}