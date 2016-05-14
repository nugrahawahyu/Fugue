namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;

class BlinkingLed : public Led
{
public:
    unsigned long interval = 2000;

    BlinkingLed(int pin, Sensor* sensor=NULL, unsigned long interval=2000) : Led(pin, sensor), Device(pin, sensor)
    {
        this->interval = interval;
    }

    /**
     * Gunakan facades Scheduler untuk menjadwalkan perilaku dari
     * perangkat.
     */
    void behavior()
    {
        Scheduler::every(interval, this, &BlinkingLed::toggle);
    }
};

}}