/** Framework */
#include "Arduino.h"
#include "MemoryFree.h"
#include "vendor/autoload.h"

/** App */
#include "app/autoload.h"

using namespace Nugraha::TugasAkhirWahyu;
using App::Controller;

Foundation::App* controller = new Foundation::App(new Controller());