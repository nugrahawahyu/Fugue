namespace Nugraha { namespace Contracts { namespace Devices {
using Nugraha::Contracts::Foundation::LoggerContract;

class DeviceContract 
{
public:
    virtual void turnOn()=0;
    virtual void turnOff()=0;
    virtual void behavior()=0;
    virtual void initialize()=0;
    virtual void setLogger(LoggerContract* logger)=0;
    virtual LoggerContract* getLogger()=0;
};

}}}