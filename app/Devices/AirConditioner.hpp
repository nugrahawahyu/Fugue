namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;
using Nugraha::Devices::Drivers::AirConditionerDriver;

class AirConditioner : public virtual Device
{
public:
    AirConditioner(int pin, Sensor* sensor=NULL) : Device(pin, sensor) {}

    void initialize()
    {
        pinMode(this->pin, OUTPUT);
        setDriver(new AirConditionerDriver());
    }

    void behavior()
    {

    }
};

}}