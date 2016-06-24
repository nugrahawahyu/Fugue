namespace Nugraha { namespace Foundation {
using Nugraha::Traits::HasLogger;
using Nugraha::Collections::Vector;
using Nugraha::Contracts::Devices::DeviceContract;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Services::ServiceContract;
using Nugraha::Contracts::Foundation::BoardContract;
using Nugraha::Contracts::Foundation::LoggerContract;
using Nugraha::Contracts::Collections::CollectionContract;
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;

class BoardKernel : public virtual BoardContract, public HasLogger
{  
protected:
    CollectionContract<Device*>* devicesCollection;
    CollectionContract<Sensor*>* sensorsCollection;
    CollectionContract<ServiceContract*>* servicesCollection;
    Device* Default = NULL;

    void initializeAll()
    {
        /** Inisialisasi setiap Device. */
        for(int i=0; i<devicesCollection->count(); i++) {
            if(devicesCollection->getMemberAt(i) != NULL) {
                devicesCollection->getMemberAt(i)->setLogger(logger);
            }
        }
    }
    
public:
    BoardKernel()
    {
        devicesCollection = new Vector<Device*>();
        sensorsCollection = new Vector<Sensor*>();
        servicesCollection = new Vector<ServiceContract*>();
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
        for(int i=0; i<devicesCollection->count(); i++) {
            if(devicesCollection->getMemberAt(i) != NULL) {
                devicesCollection->getMemberAt(i)->behavior();
            }
        }
        
        /** Jalankan service setiap Gateway. */
        for(int i=0; i<servicesCollection->count(); i++) {
            if(servicesCollection->getMemberAt(i) != NULL) {
                servicesCollection->getMemberAt(i)->service();
                servicesCollection->getMemberAt(i)->setLogger(logger);
                servicesCollection->getMemberAt(i)->setBoard(this);
            }
        }
    }

    void attachDevice(Device* device)
    {
        devicesCollection->add(device);
    }

    void attachSensor(Sensor* sensor)
    {
        sensorsCollection->add(sensor);
    }

    void attachService(ServiceContract* gateway)
    {
        servicesCollection->add(gateway);
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
                if((device=getDeviceByPin(pin)) != NULL) {
                    device->turnOn();
                }
            } else if(action=="turnOff") {
                if((device=getDeviceByPin(pin)) != NULL) {
                    device->turnOff();
                }
            } else if(action=="toggle") {
                if((device=getDeviceByPin(pin)) != NULL) {
                    device->toggle();
                }
            }
        }
    }

    Device* getDeviceByPin(int pin)
    {
        Device* device;
        for(int i=0; i<devicesCollection->count(); i++) {
            device = devicesCollection->getMemberAt(i);
            if(device != NULL) {
                if(device->getPin() == pin) {
                    return device;
                }
            }
        }
        return NULL;
    }

    ~BoardKernel()
    {
        delete servicesCollection;
        delete devicesCollection;
        delete sensorsCollection;
        delete logger;
    }
};

}}