using Nugraha::Support::Facades::Debug;
using Nugraha::Support::Facades::Fluid;
using Nugraha::Support::Facades::Route;
using Nugraha::Support::Facades::Scheduler::Scheduler;

/** Sensors */
#include "../Sensors/PirSensor.hpp"

/** Devices */
#include "../Devices/Lampu.hpp"
#include "../Devices/LampuPir.hpp"
#include "../Devices/Led.hpp"
#include "../Devices/BlinkingLed.hpp"
#include "../Devices/AirConditioner.hpp"

/** Gateways */
#include "../Gateways/HTTPClients/PersistentHttp.hpp"
#include "../Gateways/HTTPClients/NonPersistentHttp.hpp"
#include "../Gateways/WebServer/Server.hpp"

/** Boards */
#include "../Boards/Arduino.hpp"
#include "../Boards/WemosD1.hpp"