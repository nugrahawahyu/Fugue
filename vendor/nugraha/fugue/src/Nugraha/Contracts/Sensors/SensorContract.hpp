namespace Nugraha { namespace Contracts { namespace Sensors {
using Nugraha::Foundation::Logger;

class SensorContract 
{
public:
    /**
     * Mendapatkan hasil pembacaan sensor.
     *
     * @return int
     */
    virtual ~SensorContract() {}
    virtual int getId()=0;
    virtual double readMeasurementValue()=0;
    virtual void setLogger(Logger* logger)=0;
    virtual Logger* getLogger()=0;   
};

}}}