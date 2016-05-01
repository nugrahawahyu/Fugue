#ifndef _SENSORCONTRACT_H_
#define _SENSORCONTRACT_H_

#include "DriverContract.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Sensors {

    class SensorContract {
    public:
        int id;
        int pin;
        const char* name;

        SensorContract(int id, int pin, const char* name) 
        {
            this->id = id;
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