namespace Tests { 
using App::Boards::Arduino;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;

class StandardCppTest : public BaseController
{
public:

    void setup()
    {
        Debug::printFreeMemory();
    }

    void loop()
    {
    }
};

}