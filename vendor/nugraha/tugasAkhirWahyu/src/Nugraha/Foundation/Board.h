namespace Nugraha { namespace TugasAkhirWahyu { namespace Foundation {
using Nugraha::TugasAkhirWahyu::Devices::Device;
using Nugraha::TugasAkhirWahyu::Sensors::Sensor;

class Board 
{  
public:
    Device* devices;
    Sensor* sensors;

    Board(int numOfPin)
    {

    }
};

}}}