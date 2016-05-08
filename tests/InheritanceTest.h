namespace Tests { 
using App::Devices::Led;
using App::Boards::Arduino;
using Nugraha::Devices::Device;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;


class InheritanceTest : public BaseController
{
public:
    std::vector<Device*> devices;

    void setup()
    {
        devices.push_back(new Led(13, NULL, NULL));

        Debug::println(devices.size());
        printDevicesPin();
    }

    void loop()
    {
    }

    void printDevicesPin()
    {
        for(int i=0; i<devices.size(); i++) {
            Debug::println(devices[i]->pin);
        }
    }
};

}