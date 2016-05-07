namespace Nugraha { namespace Foundation {
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;

class Board 
{  
public:
    Device* devices;
    Sensor* sensors;

    Board(int numOfPin)
    {

    }
};

}}