namespace Nugraha { namespace Sensors { namespace Drivers {

class GenericDriver : public virtual Driver
{
protected:

public:
    double readMeasurementValue(int pin)
    {
        return digitalRead(pin);
    }
};

}}}