#ifndef Nugraha_TugasAkhirWahyu_Devices_Driver
#define Nugraha_TugasAkhirWahyu_Devices_Driver
#include "../Contracts/Devices/DriverContract.h"


namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices { 

    using Nugraha::TugasAkhirWahyu::Contracts::Devices::DriverContract;

    class Driver: public DriverContract {
    public:
        bool turnOn(int pin) 
        {
            
        }

        bool turnOff(int pin) 
        {
            
        }
    };

}}}

#endif