using Nugraha::Support::Facades::Debug;
using Nugraha::Support::Facades::Fluid;
using Nugraha::Support::Facades::Route;
using Nugraha::Support::Facades::Scheduler::Scheduler;

/** Devices */
#include "../Devices/Led.h"
#include "../Devices/BlinkingLed.h"
#include "../Devices/AirConditioner.h"

/** Gateways */
#include "../Gateways/HTTPClients/PersistentHttp.h"
#include "../Gateways/HTTPClients/NonPersistentHttp.h"
#include "../Gateways/WebServer/Server.h"

/** Boards */
#include "../Boards/Arduino.h"
#include "../Boards/WemosD1.h"