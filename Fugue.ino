/**
 * TugasAkhirWahyu - Sebuah program Arduino untuk Home Automation.
 *
 * @package TugasAkhirWahyu
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>
 */
#include "Fugue.h"
namespace Main {
using App::Devices::Led;
using namespace App::Boards;
using Nugraha::Foundation::Board;
using Nugraha::Foundation::BaseController;

class Controller : public virtual BaseController
{
public:
    void setup()
    {
        Debug::isDebugMode = true;
        board->initialize();
    }

    void loop()
    {
        board->automate();
    }
};
}
#include "bootstrap/bootstrap.h"
