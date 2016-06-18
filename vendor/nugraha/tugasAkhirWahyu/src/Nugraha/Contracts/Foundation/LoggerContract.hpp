namespace Nugraha { namespace Contracts { namespace Foundation {

class LoggerContract
{
public:
    virtual ~LoggerContract() {}
    virtual void addNotification(int pin, bool state)=0;
    virtual void addConnectionInfo(String parameter, String value)=0;
    virtual void addSensorMeasurement(String sensorName, double measurementValue)=0;
    virtual String getLogMessage()=0;
    virtual void printToSerial()=0;
};

}}}
