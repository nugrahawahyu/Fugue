namespace App { namespace Boards { 
using namespace App::Devices;
using namespace App::Gateways;
using Nugraha::Foundation::Board;
using Nugraha::Devices::Drivers::GenericDriver;

class Arduino : public virtual Board {
protected:
    void gateways()
    {
        
    }

    void devices()
    {
        this->attachDevice(new Led(D9, NULL));
    }

    void sensors(){}
};

}}