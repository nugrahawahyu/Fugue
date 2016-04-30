#include "../nugraha/tugasAkhirWahyu/src/TugasAkhirWahyu/HomeAutomation/Home.h"
#include "../nugraha/tugasAkhirWahyu/src/TugasAkhirWahyu/Devices/GenericDevice.h"
#include "../nugraha/tugasAkhirWahyu/src/TugasAkhirWahyu/Sensors/Sensor.h"

using namespace Nugraha::TugasAkhirWahyu;

using HomeAutomation::Home;
using Devices::GenericDevice;
using Sensors::Sensor;

Home* myHome;
GenericDevice* lampu = new GenericDevice(new Sensor(1, 1, "sensor"));

void forDebugging()
{

}