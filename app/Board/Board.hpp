namespace App { namespace Boards { 
using namespace App::Devices;
using namespace App::Sensors;
using Nugraha::Foundation::BoardKernel;
using App::Services::WebServer::Server;
using namespace App::Services::HttpClients;
                
class Board : public virtual BoardKernel {
protected:

    void services()
    {
        this->attachService(new PersistentHttp(std::map<String, String>({
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
        this->attachDevice(new Lampu(D2));
        this->attachDevice(new Lampu(D3));
        this->attachDevice(new Lampu(D4));
        this->attachDevice(new Lampu(D5));
        this->attachDevice(new AirConditioner(D6));
        this->attachDevice(new Led(BUILTIN_LED, new PirSensor(D7)));
    }

    void sensors()
    {

    }
};

}}