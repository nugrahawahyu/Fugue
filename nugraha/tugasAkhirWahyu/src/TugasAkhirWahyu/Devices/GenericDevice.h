#ifndef _GENERICDEVICE_H_
#define _GENERICDEVICE_H_

#include "../Contracts/Devices/DeviceContract.h"
#include "../Sensors/Sensor.h"
#include "../Sensors/GenericSensor.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices {

    using Nugraha::TugasAkhirWahyu::Contracts::Devices::DeviceContract;
    using Nugraha::TugasAkhirWahyu::Sensors::Sensor;
    using Nugraha::TugasAkhirWahyu::Sensors::GenericSensor;

    class GenericDevice: public DeviceContract {
    public:
        GenericDevice(Sensor* sensor)
        {
            this->sensor = sensor;
        }

        void turnOn()
        {
            this->isOn = true;
        }

        void turnOff()
        {
            this->isOn = false;
        }
    };
}}}

#endif