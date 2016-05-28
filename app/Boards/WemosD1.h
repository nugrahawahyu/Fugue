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
        
        this->attachGateway(new NonPersistentHttp(std::map<String, String>({
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
        // this->attachDevice(new BlinkingLed(D2, NULL, 1000));
        // this->attachDevice(new BlinkingLed(D3, NULL, 1300));
        // this->attachDevice(new BlinkingLed(D4, NULL, 1600));
        this->attachDevice(new AirConditioner(D13, NULL));
        this->attachDevice(new Led(BUILTIN_LED, NULL));
    }

    void sensors()
    {
        
    }
};

}}