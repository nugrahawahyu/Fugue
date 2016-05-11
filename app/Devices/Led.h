namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;

class Led : public virtual Device
{
public:
    Led(int pin, Sensor* sensor=NULL) : Device(pin, sensor) {}

    void initialize()
    {
        pinMode(this->pin, OUTPUT);
        // Debug::println(this->pin);
    }

    void behavior() {}
};

}}