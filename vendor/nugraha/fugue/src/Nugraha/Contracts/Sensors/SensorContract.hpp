namespace Nugraha { namespace Contracts { namespace Sensors {
using Nugraha::Contracts::Foundation::LoggerContract;

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
    virtual void setLogger(LoggerContract* logger)=0;
    virtual LoggerContract* getLogger()=0;   
};

}}}