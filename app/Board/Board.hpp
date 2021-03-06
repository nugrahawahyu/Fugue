namespace App { namespace Boards { 
using namespace App::Devices;
using namespace App::Sensors;
using namespace App::Services;
using Nugraha::Foundation::BoardKernel;
                
class Board : public virtual BoardKernel {
protected:

    void services()
    {
        this->attachService(new TemperatureLogger());
        this->attachService(new HttpClient(std::map<String, String>({
            { "host"         , env::httpClient::host },
            { "mode"         , env::httpClient::mode },
            { "publishKey"   , env::httpClient::publishKey },
            { "subscribeKey" , env::httpClient::subscribeKey },
            { "signature"    , env::httpClient::signature },
            { "channelName"  , env::httpClient::channelName },
            { "callback"     , env::httpClient::callback }
        }), true));
    }

    void devices()
    {
        this->attachDevice(new Lampu(D2));
        this->attachDevice(new Lampu(D3));
        this->attachDevice(new Lampu(D4));
        this->attachDevice(new Lampu(D5));
        this->attachDevice(new AirConditioner(D8));
        this->attachDevice(new Led(BUILTIN_LED));
    }

    void sensors()
    {
        this->attachSensor(new Ds18B20(D6));
    }
};

}}