namespace Nugraha { namespace Foundation {
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;

class Board 
{  
protected:
    virtual void devices()=0;
    virtual void sensors()=0;

    void initializeDevicesAndSensors()
    {
        for(int i=0; i<devicesCollection.size(); i++) {
            devicesCollection[i]->initialize();
        }
    }
    
public:
    std::vector<Device*> devicesCollection;
    std::vector<Sensor*> sensorsCollection;
    
    void initialize()
    {
        devices();
        sensors();
        initializeDevicesAndSensors();
    }

    void automate()
    {
        for(int i=0; i<devicesCollection.size(); i++) {
            devicesCollection[i]->behavior();
        }
    }
};

}}