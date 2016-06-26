/**
 * ---------------------------------------------------------------|
 *                              Contracts
 *                                  |
 *                  +---------------+---------------+ 
 *                  |                               |
 *          +-----Driver----+                    Gateways 
 *          |               |                       |
 *          |            Sensors                    |
 *          |               |                       |
 *          +----Devices ---+                       |
 *                  |                               | 
 *                  +---------------+---------------+  
 *                                  |
 *                              Foundation
 * ---------------------------------------------------------------|
 */

/** Globals */
#include "../Support/helpers/Scheduler.hpp"

/** Contracts */
 namespace Nugraha{namespace Foundation{class Logger;}}
#include "../Contracts/Foundation/LoggerContract.hpp"
#include "../Contracts/Support/Facades/Scheduler/EventContract.hpp"
#include "../Contracts/Foundation/BoardContract.hpp"
#include "../Contracts/Services/ServiceContract.hpp"
#include "../Contracts/Drivers/Sensors/DriverContract.hpp"
#include "../Contracts/Sensors/SensorContract.hpp"
#include "../Contracts/Drivers/Devices/DriverContract.hpp"
#include "../Contracts/Devices/DeviceContract.hpp"
#include "../Contracts/Collections/CollectionContract.hpp"

 /** Foundation/Logger */
#include "../Foundation/Logger.hpp"

/** Collections */
#include "../Collections/Collection.hpp"
#include "../Collections/Vector.hpp"

 /** Traits */
#include "../Traits/HasNotification.hpp"
#include "../Traits/HasLogger.hpp"
#include "../Traits/HasId.hpp"
#include "../Traits/RecordableInstance.hpp"

/** Support/Facades */
#include "../Support/Facades/Debug.hpp"
#include "../Support/Facades/Fluid.hpp"
#include "../Support/Facades/Scheduler/BaseEvent.hpp"
#include "../Support/Facades/Scheduler/Event.hpp"
#include "../Support/Facades/Scheduler/StaticEvent.hpp"
#include "../Support/Facades/Scheduler/Scheduler.hpp"
#include "../Support/Facades/Route.hpp"
using Nugraha::Support::Facades::Debug;
using Nugraha::Support::Facades::Fluid;
using Nugraha::Support::Facades::Route;
using Nugraha::Support::Facades::Scheduler::Scheduler;

/** Drivers/Sensors */
#include "../Drivers/Sensors/Driver.hpp"
#include "../Drivers/Sensors/GenericDriver.hpp"

/** Drivers/Devices */
#include "../Drivers/Devices/Driver.hpp"
#include "../Drivers/Devices/GenericDriver.hpp"
#include "../Drivers/Devices/SinkModeDriver.hpp"
#include "../Drivers/Devices/AirConditionerDriver.hpp"

/** Services */
#include "../Services/Service.hpp"
#include "../Services/Esp8266/WifiHttpClient.hpp"
#include "../Services/Esp8266/WifiWebServer.hpp"

/** Sensors */
#include "../Sensors/Sensor.hpp"

/** Devices */
#include "../Devices/Device.hpp"

/** Foundation */
#include "../Foundation/BoardKernel.hpp"
#include "../Foundation/BaseController.hpp"
#include "../Foundation/Application.hpp"