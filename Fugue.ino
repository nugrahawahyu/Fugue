/**
 * TugasAkhirWahyu - Sebuah program Arduino untuk Home Automation.
 *
 * @package TugasAkhirWahyu
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>
 */
#include "Fugue.h"
using App::Devices::Led;
using App::Boards::ArduinoMega;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;

class Controller : public BaseController
{
protected:
    ArduinoMega* homeAutomation;

public:
    /** Inisialisasi board Arduino dan devices. */
    void setup()
    {
        homeAutomation = new ArduinoMega();
        homeAutomation->initialize();
        Debug::printFreeMemory();
    }

    /** Fungsi yang terus dieksekusi selagi Arduino masih on. */
    void loop()
    {
        homeAutomation->automate();
    }
};

Application* controller = new Application(new Controller());
#include "bootstrap/bootstrap.h"