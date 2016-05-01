#ifndef TUGASAKHIRWAHYU_DEVICES_GENERICDEVICE_H_
#define TUGASAKHIRWAHYU_DEVICES_GENERICDEVICE_H_
    
#include "bootstrap.h"
#include "../Sensors/GenericSensor.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices {

    using Nugraha::TugasAkhirWahyu::Contracts::Devices::DeviceContract;
    using Nugraha::TugasAkhirWahyu::Contracts::Sensors::SensorContract;
    using Nugraha::TugasAkhirWahyu::Sensors::GenericSensor;

    class GenericDevice: public DeviceContract {
    public:

        GenericDevice(SensorContract* sensor = 0) : DeviceContract(sensor)
        {
        }

        void autoOn(){}

        void autoOff(){}
    };
}}} 

#endif

