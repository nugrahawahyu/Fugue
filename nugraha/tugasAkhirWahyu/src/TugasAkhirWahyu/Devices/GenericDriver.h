#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "../Contracts/Devices/DriverContract.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Devices {

    using Nugraha::TugasAkhirWahyu::Contracts::Devices::DriverContract;

    class Driver: public DriverContract {
    public:
        void turnOn(int pin) 
        {
            
        }

        void turnOff(int pin) 
        {
            
        }
    };
}}}

#endif