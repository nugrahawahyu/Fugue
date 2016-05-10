namespace Nugraha { namespace Foundation {
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
// using Nugraha::Collections::Vector;
using Nugraha::Collections::SimpleVector;
using Nugraha::Collections::Collection;


class Board 
{  
protected:
    Collection<Device*>* devicesCollection = new SimpleVector<Device*>();
    Collection<Sensor*>* sensorsCollection = new SimpleVector<Sensor*>();

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