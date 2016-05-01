#include "../nugraha/tugasAkhirWahyu/src/TugasAkhirWahyu/HomeAutomation/Home.h"
#include "../nugraha/tugasAkhirWahyu/src/TugasAkhirWahyu/Devices/GenericDevice.h"
#include "../nugraha/tugasAkhirWahyu/src/TugasAkhirWahyu/Sensors/GenericSensor.h"

using namespace Nugraha::TugasAkhirWahyu;

using HomeAutomation::Home;
using Devices::GenericDevice;
using Sensors::GenericSensor;

Home* myHome;
GenericDevice* lampu = new GenericDevice(new GenericSensor(1, 1, "sensor"));

void forDebugging()
{
    
}