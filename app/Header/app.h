using namespace Nugraha::Support::Facades::Scheduler;

/** Sensors */
#include "../Sensors/PirSensor.hpp"
#include "../Sensors/Ds18B20.hpp"

/** Devices */
#include "../Devices/Lampu.hpp"
#include "../Devices/LampuPir.hpp"
#include "../Devices/Led.hpp"
#include "../Devices/BlinkingLed.hpp"
#include "../Devices/AirConditioner.hpp"

/** Services */
#include "../Services/HttpClient.hpp"
#include "../Services/TemperatureLogger.hpp"

/** Boards */
#include "../Board/Board.hpp"