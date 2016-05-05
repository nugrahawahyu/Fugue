#ifndef Nugraha_TugasAkhirWahyu_Contract_Sensors_SensorContract
#define Nugraha_TugasAkhirWahyu_Contract_Sensors_SensorContract
#include "DriverContract.h"


namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Sensors {

    class SensorContract {
    public:
        int id;
        int pin;
        const char* name;

        SensorContract(int pin, const char* name) 
        {
            this->pin = pin;
            this->name = name;
            this->driver = 0;
        }

        /**
         * Mendapatkan hasil pembacaan sensor.
         *
         * @return int
         */
        virtual double getMeasurementValue()=0;

    protected:
        DriverContract* driver;
    };

}}}}

#endif