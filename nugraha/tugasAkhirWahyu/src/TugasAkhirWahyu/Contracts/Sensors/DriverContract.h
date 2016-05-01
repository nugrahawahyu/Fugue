#ifndef _DRIVERCONTRACT_H_
#define _DRIVERCONTRACT_H_


namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Sensors {

    class DriverContract {
    public:
        virtual void getMeasurementValue(int pin);
    };
}}}}

#endif