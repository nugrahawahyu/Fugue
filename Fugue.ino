/**
 * Fugue - IoT platform
 *
 * @package Nugraha
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>
 */

#include "Fugue.h"

namespace Main {
using Nugraha::Foundation::BaseController;

class Controller : public BaseController
{
public:
    void setup()
    {
        Debug::isDebugMode = true;
        if(!env::wifi::obtainIpAddressAutomatically) {
            WiFi.config(env::wifi::ip, env::wifi::gateway, env::wifi::subnet, env::wifi::dns1, env::wifi::dns2);
        }
        board->initialize();
    }

    void loop()
    {
        Scheduler::handleEvents();
    }
};

}
#include "bootstrap/bootstrap.hpp"