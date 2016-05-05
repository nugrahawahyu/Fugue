#ifndef Nugraha_TugasAkhirWahyu_Contract_Devices_DeviceContract
#define Nugraha_TugasAkhirWahyu_Contract_Devices_DeviceContract
#include "../../Contracts/Sensors/SensorContract.h"
#include "DriverContract.h"


namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Devices {

using Nugraha::TugasAkhirWahyu::Contracts::Sensors::SensorContract;

class DeviceContract {

    public:
        virtual void turnOn()=0;
        virtual void turnOff()=0;
        virtual void rules()=0;
};

}}}}

#endif