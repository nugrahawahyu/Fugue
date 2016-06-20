namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;

class BlinkingLed : public Led
{
public:
    unsigned long interval;

    BlinkingLed(int pin, Sensor* sensor=NULL, unsigned long interval=2000) : Led(pin, sensor), Device(pin, sensor)
    {
        this->interval = interval;
    }

    void behavior()
    {
        Scheduler::every(interval, [=]() {
            this->toggle();
        });
    }
};

}}
