namespace Nugraha { namespace Foundation {
using Nugraha::Collections::Vector;
using Nugraha::Collections::Collection;
using Nugraha::Contracts::Devices::DeviceContract;
using Nugraha::Contracts::Sensors::SensorContract;
using Nugraha::Contracts::Gateways::GatewayContract;
using Nugraha::Contracts::Foundation::BoardContract;


class Board : public virtual BoardContract
{  
protected:
    Collection<DeviceContract*>* devicesCollection;
    Collection<SensorContract*>* sensorsCollection;
    Collection<GatewayContract*>* gatewaysCollection;

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
        /** Jalankan service setiap Gateway. */
        for(int i=0; i<gatewaysCollection->count(); i++) {
            if(gatewaysCollection->getMemberAt(i) != NULL) {
                gatewaysCollection->getMemberAt(i)->service();
            }
        }

        /** Jalankan behavior setiap Device. */
        for(int i=0; i<devicesCollection->count(); i++) {
            if(devicesCollection->getMemberAt(i) != NULL) {
                devicesCollection->getMemberAt(i)->behavior();
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
    ~Board()
    {
        delete devicesCollection;
        delete sensorsCollection;
    }
};

}}