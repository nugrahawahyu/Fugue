namespace App { namespace Boards { 
using namespace App::Devices;
using Nugraha::Foundation::Board;
using App::Gateways::WebServer::Server;
using namespace App::Gateways::HttpClients;
                
class WemosD1 : public virtual Board {
protected:

    void gateways()
    {
        // this->attachGateway(new Server());
        
        this->attachGateway(new PersistentHttp(std::map<String, String>({
            { "host"         , env::httpClient::host },
            { "mode"         , env::httpClient::mode },
            { "publishKey"   , env::httpClient::publishKey },
            { "subscribeKey" , env::httpClient::subscribeKey },
            { "signature"    , env::httpClient::signature },
            { "channelName"  , env::httpClient::channelName },
            { "callback"     , env::httpClient::callback }
        })));
    }

    void devices()
    {
        this->attachDevice(new Lampu(D2, NULL));
        this->attachDevice(new Lampu(D3, NULL));
        this->attachDevice(new Lampu(D4, NULL));
        this->attachDevice(new Lampu(D5, NULL));
        this->attachDevice(new AirConditioner(D6, NULL));
        this->attachDevice(new Led(BUILTIN_LED, NULL));
    }

    void sensors()
    {
        
    }
};

}}