#ifndef _SENSOR_H_
#define _SENSOR_H_


namespace Nugraha { namespace TugasAkhirWahyu { namespace Sensors {

    class Sensor {

    public:
        
        int id;
        int pin;
        const char* name;

        Sensor(int id, int pin, const char* name) 
        {
            id = id;
            pin = pin;
            name = name;
        }

        /**
         * Mendapatkan hasil pembacaan sensor.
         *
         * @return int
         */
        virtual double getMeasurementValue()
        {
            
        }

    };

}}}

#endif