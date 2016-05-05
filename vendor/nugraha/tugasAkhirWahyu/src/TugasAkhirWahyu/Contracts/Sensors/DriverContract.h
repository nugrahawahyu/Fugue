#ifndef Nugraha_TugasAkhirWahyu_Contract_Sensors_DriverContract
#define Nugraha_TugasAkhirWahyu_Contract_Sensors_DriverContract

namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Sensors {

    class DriverContract {
    public:
        virtual void getMeasurementValue(int pin)=0;
    };
}}}}

#endif