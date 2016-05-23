namespace Nugraha { namespace Contracts { namespace Foundation {

class LoggerContract
{
public:
    virtual void addNotification(int code, String message)=0;
    virtual void addSensorMeasurement(String sensorName, String measurementValue)=0;
    virtual String getLogMessage()=0;
    virtual void printToSerial()=0;
};

}}}
