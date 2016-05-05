#ifndef Nugraha_TugasAkhirWahyu_Devices_Device
#define Nugraha_TugasAkhirWahyu_Devices_Device
#include "Includes/bootstrap.h"
#include "../Sensors/GenericSensor.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices {

using Nugraha::TugasAkhirWahyu::Contracts::Devices::DeviceContract;
using Nugraha::TugasAkhirWahyu::Contracts::Sensors::SensorContract;
using Nugraha::TugasAkhirWahyu::Sensors::GenericSensor;

class Device: public DeviceContract {
public:

    int pin;
    char* name;
    bool isOn;

    Device(int pin, SensorContract* sensor)
    {
        this->sensor = sensor;
        this->isOn = false;
        this->sensor = 0;
        this->driver = 0;
    }

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

    void setSensor(SensorContract* sensor)
    {
        this->sensor = sensor;
    }

    void setDriver(DriverContract* driver)
    {
        this->driver = driver;
    }


protected:
    SensorContract* sensor;
    DriverContract* driver;
};

}}} 
#endif

