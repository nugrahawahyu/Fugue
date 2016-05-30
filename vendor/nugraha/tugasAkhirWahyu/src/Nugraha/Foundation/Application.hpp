namespace Nugraha { namespace Foundation {
using Nugraha::Contracts::Foundation::BoardContract;

class Application
{
public:
    BaseController* controller;
    int serialBaudRate;
    bool beginSerial;

    Application(BaseController* controller, BoardContract* board, int serialBaudRate, bool beginSerial)
    {
        this->controller = controller;
        this->controller->board = board;
        this->serialBaudRate = serialBaudRate;
        this->beginSerial = beginSerial;
    }

    virtual ~Application() {}

    virtual void setup()
    {
        this->controller->setup();
    }
    
    virtual void loop()
    {
        this->controller->loop();
    }
};

}}
