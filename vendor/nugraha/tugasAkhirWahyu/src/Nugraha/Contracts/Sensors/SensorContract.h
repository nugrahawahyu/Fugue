namespace Nugraha { namespace Contracts { namespace Sensors {

class SensorContract 
{
public:
    /**
     * Mendapatkan hasil pembacaan sensor.
     *
     * @return int
     */
    virtual double readMeasurementValue()=0;
};

}}}