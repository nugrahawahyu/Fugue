namespace Nugraha { namespace Foundation {

class Application
{
public:
    BaseController* controller;
    int serialBaudRate;
    bool beginSerial;

    Application(BaseController* controller, Board* board, int serialBaudRate, bool beginSerial)
    {
        this->controller = controller;
        this->controller->board = board;
        this->serialBaudRate = serialBaudRate;
        this->beginSerial = beginSerial;
    }

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
