namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;
using Nugraha::Devices::Driver;

class Led : public Device
{
public:
    Led(int pin, Driver* driver, Sensor* sensor=NULL) : Device(pin, driver, sensor){}

    void initialize()
    {
        pinMode(this->pin, OUTPUT);
    }

    void behavior()
    {
        digitalWrite(this->pin, HIGH);
        delay(1000);
        digitalWrite(this->pin, LOW);
        delay(1000);
    }

};

}}