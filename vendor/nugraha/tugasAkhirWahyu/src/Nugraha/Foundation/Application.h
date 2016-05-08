namespace Nugraha { namespace Foundation {

class Application
{
public:
    BaseController* controller;

    Application(BaseController* controller)
    {
        this->controller = controller;
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
