#ifndef _GENERICSENSOR_H_
#define _GENERICSENSOR_H_

#include "../Contracts/Sensors/SensorContract.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Sensors {

    using Nugraha::TugasAkhirWahyu::Contracts::Sensors::SensorContract;

    class GenericSensor: public SensorContract {

    public:

        GenericSensor(int id, int pin, const char* name) : SensorContract(id, pin, name){}
        
        double getMeasurementValue()
        {

        }
    };

}}}

#endif