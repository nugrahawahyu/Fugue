namespace Nugraha { namespace Drivers { namespace Sensors {

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