#ifndef Nugraha_TugasAkhirWahyu_Foundation_App
#define Nugraha_TugasAkhirWahyu_Foundation_App
#include "BaseController.h"

namespace Nugraha { namespace TugasAkhirWahyu { namespace Foundation {

class App {
public:
    BaseController* controller;

    App(BaseController* controller)
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

}}}
#endif