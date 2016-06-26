namespace Nugraha { namespace Foundation {
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
using Nugraha::Services::Service;
using Nugraha::Traits::HasLogger;
using Nugraha::Collections::Vector;
using Nugraha::Contracts::Foundation::BoardContract;

class BoardKernel : public virtual BoardContract, public HasLogger
{  
protected:
    std::vector<Device*> devicesCollection;
    std::vector<Sensor*> sensorsCollection;
    std::vector<Service*> servicesCollection;
    Device* Default = NULL;

    void initializeAll()
    {
        /** Inisialisasi setiap Device. */
        for(int i=0; i<devicesCollection.size(); i++) {
            if(devicesCollection[i] != NULL) {
                devicesCollection[i]->setLogger(logger);
            }
        }
    }
    
public:
    BoardKernel()
    {
        setLogger(new Logger());
    }

    void initialize()
    {
        sensors();
        devices();
        services();
        initializeAll();
        automate();
    }

    void automate()
    {
        /** Jalankan behavior setiap Device. */
        for(int i=0; i<devicesCollection.size(); i++) {
            if(devicesCollection[i] != NULL) {
                devicesCollection[i]->behavior();
            }
        }
        
        /** Jalankan service setiap Gateway. */
        for(int i=0; i<servicesCollection.size(); i++) {
            if(servicesCollection[i] != NULL) {
                servicesCollection[i]->service();
                servicesCollection[i]->setLogger(logger);
                servicesCollection[i]->setBoard(this);
            }
        }
    }

    void attachDevice(Device* device)
    {
        devicesCollection.push_back(device);
    }

    void attachSensor(Sensor* sensor)
    {
        sensorsCollection.push_back(sensor);
    }

    void attachService(Service* gateway)
    {
        servicesCollection.push_back(gateway);
    }

    void executeUserCommand(String userCommands)
    {
        Device* device;
        DynamicJsonBuffer jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(userCommands);
        if (!root.success()) {
            Serial.println("parseObject() failed");
            return;
        }

        for(int i=0; i<root["commands"].size(); i++) {
            int pin = root["commands"][i]["pin"];
            String action = root["commands"][i]["action"];

            if(action=="turnOn") {
                if((device = Device::wherePin(pin)) != NULL) {
                    device->turnOn();
                }
            } else if(action=="turnOff") {
                if((device = Device::wherePin(pin)) != NULL) {
                    device->turnOff();
                }
            } else if(action=="toggle") {
                if((device = Device::wherePin(pin)) != NULL) {
                    device->toggle();
                }
            }
        }
    }

    virtual ~BoardKernel()
    {

    }
};

}}