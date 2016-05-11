namespace Nugraha { namespace Foundation {
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
using Nugraha::Collections::Vector;
using Nugraha::Collections::Collection;


class Board 
{  
protected:
    Collection<Device*>* devicesCollection;
    Collection<Sensor*>* sensorsCollection;

    Device* Default = NULL;

    virtual void devices()=0;
    virtual void sensors()=0;

    void initializeDevicesAndSensors()
    {
        for(int i=0; i<devicesCollection->count(); i++) {
            if(devicesCollection->getMemberAt(i) != NULL) {
                devicesCollection->getMemberAt(i)->initialize();
            }
        }
    }
    
public:
    Board()
    {
        devicesCollection = new Vector<Device*>();
        sensorsCollection = new Vector<Sensor*>();
    }
    
    void initialize()
    {
        devices();
        sensors();
        initializeDevicesAndSensors();
    }

    void automate()
    {
        for(int i=0; i<devicesCollection->count(); i++) {
            if(devicesCollection->getMemberAt(i) != NULL) {
                devicesCollection->getMemberAt(i)->behavior();
            }
        }
    }

    void attachDevice(Device* device)
    {
        devicesCollection->add(device);
    }

    ~Board()
    {
        delete devicesCollection;
        delete sensorsCollection;
    }
};

}}