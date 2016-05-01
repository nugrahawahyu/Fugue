#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "../../Contracts/Devices/DriverContract.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices { namespace Drivers {

    using Nugraha::TugasAkhirWahyu::Contracts::Devices::DriverContract;

    class GenericDriver: public DriverContract {
    public:
        bool turnOn(int pin) 
        {
            
        }

        bool turnOff(int pin) 
        {
            
        }
    };

}}}}

#endif