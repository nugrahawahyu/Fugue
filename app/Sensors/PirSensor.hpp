namespace App { namespace Sensors { 
using Nugraha::Sensors::Sensor;

class PirSensor : public virtual Sensor
{
public:    
    PirSensor(int pin) : Sensor(pin) 
    {
        pinMode(this->pin, INPUT);
    }

    double readMeasurementValue()
    {
        return this->driver->readMeasurementValue(this->pin);
    }
};

}}