namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;

class LampuPir : public virtual Device
{
public:
    int lastMeasurementValue = LOW;

    LampuPir(int pin, Sensor* sensor) : Device(pin, sensor) {}

    void initialize()
    {
        pinMode(this->pin, OUTPUT);
        this->turnOff();
    }

    void behavior()
    {
        Scheduler::every(50, [=]() {
            int currentMeasurementValue = getSensor()->readMeasurementValue();
            if(currentMeasurementValue == HIGH && lastMeasurementValue == 0) {
                this->toggle();
            }
            lastMeasurementValue = currentMeasurementValue;
        });
    }
};

}}