namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Devices {

class DeviceContract 
{
public:
    virtual void turnOn()=0;
    virtual void turnOff()=0;
    virtual void behavior()=0;
};

}}}}