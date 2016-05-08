namespace App { namespace Boards { 
using App::Devices::Led;
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
using Nugraha::Foundation::Board;
using Nugraha::Devices::Drivers::GenericDriver;

class ArduinoMega : public virtual Board {
protected:
    void devices()
    {
        devicesCollection.push_back(new Led(13,NULL,NULL));
    }

    void sensors()
    {

    }
};

}}