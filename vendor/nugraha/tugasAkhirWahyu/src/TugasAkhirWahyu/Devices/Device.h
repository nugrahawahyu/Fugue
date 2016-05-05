namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices {
using Nugraha::TugasAkhirWahyu::Contracts::Devices::DeviceContract;
using Nugraha::TugasAkhirWahyu::Sensors::Sensor;

class Device: public DeviceContract 
{
protected:
    Sensor* sensor;
    Driver* driver;
    
public:
    int pin;
    char* name;
    bool isOn;

    Device(int pin, Sensor* sensor)
    {
        this->sensor = sensor;
        this->isOn = false;
        this->sensor = 0;
        this->driver = 0;
    }

    virtual void behavior();

    /**
     * Menghidupkan perangkat dan mengupdate state-nya.
     * @param  Device $device
     */
    void turnOn()
    {
        if(driver->turnOn(this->pin)) {
            this->isOn = true;
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
}}} 
