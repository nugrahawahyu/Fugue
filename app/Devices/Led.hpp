namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;

class Led : public virtual Device
{
public:
    Led(int pin, Sensor* sensor=NULL) : Device(pin, sensor)
    {
        pinMode(this->pin, OUTPUT);
    }

    void behavior()
    {

    }
};

}}