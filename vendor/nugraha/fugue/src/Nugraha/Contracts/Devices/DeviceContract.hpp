namespace Nugraha { namespace Contracts { namespace Devices {
using Nugraha::Foundation::Logger;

class DeviceContract 
{
public:
    virtual ~DeviceContract() {}
    virtual void turnOn()=0;
    virtual void turnOff()=0;
    virtual void toggle()=0;
    virtual void behavior()=0;
    virtual int getPin()=0;
    virtual int getId()=0;
    virtual void setLogger(Logger* logger)=0;
    virtual Logger* getLogger()=0;
};

}}}