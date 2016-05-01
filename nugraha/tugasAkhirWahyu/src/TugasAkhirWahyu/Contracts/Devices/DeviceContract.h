#ifndef TUGASAKHIRWAHYU_CONTRACTS_DEVICES_DEVICECONTRACT_H_
#define TUGASAKHIRWAHYU_CONTRACTS_DEVICES_DEVICECONTRACT_H_
    
#include "../../Contracts/Sensors/SensorContract.h"
#include "DriverContract.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Devices {

    using Nugraha::TugasAkhirWahyu::Contracts::Sensors::SensorContract;

    class DeviceContract {

        public:
            int id;
            int pin;
            char* name;
            bool isOn;

            DeviceContract(SensorContract* sensor)
            {
                this->sensor = sensor;
                this->isOn = false;
                this->sensor = 0;
                this->driver = 0;
            }

            virtual void autoOff();

            virtual void autoOn();

            /**
             * Menghidupkan perangkat dan mengupdate state-nya.
             * @param  Device $device
             */
            void turnOn()
            {
                if(driver->turnOn(this->pin)) {
                    this->isOn = true;
                }
            }

            /**
             * Mematikan perangkat dan mengupdate state-nya.
             * @param  Device $device
             */
            void turnOff()
            {
                if(driver->turnOff(this->pin)) {
                    this->isOn = false;
                }
            }

            void setSensor(SensorContract* sensor)
            {
                this->sensor = sensor;
            }


        protected:
            SensorContract* sensor;
            DriverContract* driver;
    };
}}}}

#endif