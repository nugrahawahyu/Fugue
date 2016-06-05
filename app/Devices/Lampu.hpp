namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;

class Lampu : public virtual Device
{
public:
    Lampu(int pin, Sensor* sensor=NULL) : Device(pin, sensor) {}

    void initialize()
    {
        pinMode(this->pin, OUTPUT);
    }

    void behavior()
    {

    }
};

}}