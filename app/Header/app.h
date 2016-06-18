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

/** Services */
#include "../Services/HTTPClients/PersistentHttp.hpp"
#include "../Services/HTTPClients/NonPersistentHttp.hpp"
#include "../Services/WebServer/Server.hpp"

/** Boards */
#include "../Board/Board.hpp"