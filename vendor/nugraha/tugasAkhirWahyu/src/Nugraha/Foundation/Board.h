namespace Nugraha { namespace Foundation {
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
using Nugraha::Collections::Vector;
using Nugraha::Collections::Collection;

class Board 
{  
protected:
    Device* Default = NULL;

    virtual void devices()=0;
    virtual void sensors()=0;

    void initializeDevicesAndSensors()
    {
        for(int i=0; i<devicesCollection.size(); i++) {
            if(devicesCollection[i] != NULL) {
                devicesCollection[i]->initialize();
            }
        }
    }
    
public:
    std::vector<Device*> devicesCollection;
    std::vector<Sensor*> sensorsCollection;
    Collection ayam;
    
    void initialize()
    {
        devices();
        sensors();
        initializeDevicesAndSensors();
    }

    void automate()
    {
        for(int i=0; i<devicesCollection.size(); i++) {
            if(devicesCollection[i] != NULL) {
                devicesCollection[i]->behavior();
            }
        }
    }

    void attachDevice(Device* device)
    {
        devicesCollection.push_back(device);
    }
};

}}