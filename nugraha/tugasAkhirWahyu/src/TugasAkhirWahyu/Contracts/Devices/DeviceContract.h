#ifndef _DEVICECONTRACT_H_
#define _DEVICECONTRACT_H_

#include "../../Sensors/Sensor.h"
#include "DriverContract.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Devices {

    using Nugraha::TugasAkhirWahyu::Sensors::Sensor;

    class DeviceContract {

        public:
            int id;
            int pin;
            char* name;
            bool isOn;
            DriverContract* driver;

            /**
             * Menghidupkan perangkat dan mengupdate state-nya.
             * @param  Device $device
             */
            void turnOn()
            {
                this->isOn = true;
                driver->turnOn(this->pin);
            }

            /**
             * Mematikan perangkat dan mengupdate state-nya.
             * @param  Device $device
             */
            void turnOff()
            {
                this->isOn = false;
                driver->turnOff(this->pin);
            }

            void setSensor(Sensor* sensor)
            {
                this->sensor = sensor;
            }


        protected:
            Sensor* sensor;
    };
}}}}

#endif