/**
 * TugasAkhirWahyu - Sebuah program Arduino untuk Home Automation.
 *
 * @package TugasAkhirWahyu
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>
 */
#include "Fugue.h"
using App::Devices::Led;
using App::Boards::Arduino;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;

class Controller : public BaseController
{
protected:
    Arduino* homeAutomation;

public:
    void setup()
    {
        Debug::isDebugMode = true;
        homeAutomation = new Arduino();
        homeAutomation->initialize();
    }

    void loop()
    {
        homeAutomation->automate();
        Debug::printFreeMemory();
    }
};

Application* controller = new Application(new Controller());
#include "bootstrap/bootstrap.h"