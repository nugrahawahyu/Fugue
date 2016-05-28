/**
 * Fugue - Sebuah program Arduino untuk Home Automation.
 *
 * @package Nugraha
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>
 */
#include "Fugue.h"

namespace Main {
using Nugraha::Foundation::BaseController;

class Controller : public virtual BaseController
{
public:
    void setup()
    {
        Debug::isDebugMode = true;
        WiFi.config(env::wifi::ip, env::wifi::gateway, env::wifi::subnet, env::wifi::dns1, env::wifi::dns2);
        board->initialize();
        board->automate();
    }

    void loop()
    {
        Scheduler::handleEvents();
    }
};

}
#include "bootstrap/bootstrap.h"