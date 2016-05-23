namespace App { namespace Boards { 
using namespace App::Devices;
using Nugraha::Foundation::Board;
using App::Gateways::WebServer::Server;
using App::Gateways::HttpClients::PersistentHttp;
                
class WemosD1 : public virtual Board {
protected:

    void gateways()
    {
        // this->attachGateway(new Server());
        // this->attachGateway(new PersistentHttp());
    }

    void devices()
    {
        // this->attachDevice(new BlinkingLed(D2, NULL, 1000));
        // this->attachDevice(new BlinkingLed(D3, NULL, 1300));
        // this->attachDevice(new BlinkingLed(D4, NULL, 1600));
        this->attachDevice(new AirConditioner(D13, NULL));
        this->attachDevice(new BlinkingLed(BUILTIN_LED, NULL, 1000));
    }

    void sensors()
    {
        
    }
};

}}