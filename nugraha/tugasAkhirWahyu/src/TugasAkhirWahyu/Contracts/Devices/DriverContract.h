#ifndef TUGASAKHIRWAHYU_CONTRACT_DEVICE_DRIVERCONTRACT_H_
#define TUGASAKHIRWAHYU_CONTRACT_DEVICE_DRIVERCONTRACT_H_

namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Devices {

    class DriverContract {
    public:
        virtual bool turnOn(int pin)=0;
        virtual bool turnOff(int pin)=0;
    };
}}}}

#endif