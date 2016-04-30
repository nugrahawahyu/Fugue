#ifndef _DRIVERCONTRACT_H_
#define _DRIVERCONTRACT_H_


namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Devices {

    class DriverContract {
    public:
        virtual void turnOn(int pin);
        virtual void turnOff(int pin);
    };
}}}}

#endif