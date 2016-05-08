namespace Nugraha { namespace Contracts { namespace Sensors {

class SensorContract 
{
public:
    /**
     * Mendapatkan hasil pembacaan sensor.
     *
     * @return int
     */
    virtual void initialize()=0;
    virtual double readMeasurementValue()=0;
};

}}}