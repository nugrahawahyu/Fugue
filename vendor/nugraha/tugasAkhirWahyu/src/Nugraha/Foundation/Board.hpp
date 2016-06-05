namespace Nugraha { namespace Foundation {
using Nugraha::Traits::HasLogger;
using Nugraha::Collections::Vector;
using Nugraha::Contracts::Devices::DeviceContract;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Gateways::GatewayContract;
using Nugraha::Contracts::Foundation::BoardContract;
using Nugraha::Contracts::Foundation::LoggerContract;
using Nugraha::Contracts::Collections::CollectionContract;

class Board : public virtual BoardContract, public HasLogger
{  
protected:
    CollectionContract<DeviceContract*>* devicesCollection;
    CollectionContract<SensorContract*>* sensorsCollection;
    CollectionContract<GatewayContract*>* gatewaysCollection;
    DeviceContract* Default = NULL;

    void initializeAll()
    {
        /** Inisialisasi setiap Gateway. */
        for(int i=0; i<gatewaysCollection->count(); i++) {
            if(gatewaysCollection->getMemberAt(i) != NULL) {
                gatewaysCollection->getMemberAt(i)->initialize();
            }
        }

        /** Inisialisasi setiap Device. */
        for(int i=0; i<devicesCollection->count(); i++) {
            if(devicesCollection->getMemberAt(i) != NULL) {
                devicesCollection->getMemberAt(i)->initialize();
            }
        }
    }
    
public:
    Board()
    {
        devicesCollection = new Vector<DeviceContract*>();
        sensorsCollection = new Vector<SensorContract*>();
        gatewaysCollection = new Vector<GatewayContract*>();
        setLogger(new Logger());
    }

    void initialize()
    {
        sensors();
        devices();
        gateways();
        initializeAll();
    }

    void automate()
    {
        /** Jalankan behavior setiap Device. */
        for(int i=0; i<devicesCollection->count(); i++) {
            if(devicesCollection->getMemberAt(i) != NULL) {
                devicesCollection->getMemberAt(i)->behavior();
                devicesCollection->getMemberAt(i)->setLogger(logger);
            }
        }
        
        /** Jalankan service setiap Gateway. */
        for(int i=0; i<gatewaysCollection->count(); i++) {
            if(gatewaysCollection->getMemberAt(i) != NULL) {
                gatewaysCollection->getMemberAt(i)->service();
                gatewaysCollection->getMemberAt(i)->setLogger(logger);
                gatewaysCollection->getMemberAt(i)->setBoard(this);
            }
        }
    }

    void attachDevice(DeviceContract* device)
    {
        devicesCollection->add(device);
    }

    void attachSensor(SensorContract* sensor)
    {
        sensorsCollection->add(sensor);
    }

    void attachGateway(GatewayContract* gateway)
    {
        gatewaysCollection->add(gateway);
    }

    void executeUserCommand(String userCommands)
    {
        DeviceContract* device;
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

    DeviceContract* getDeviceByPin(int pin)
    {
        DeviceContract* device;
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

    ~Board()
    {
        delete gatewaysCollection;
        delete devicesCollection;
        delete sensorsCollection;
        delete logger;
    }
};

}}