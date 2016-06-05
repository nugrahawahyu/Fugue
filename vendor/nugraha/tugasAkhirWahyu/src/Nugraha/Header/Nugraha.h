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
#include "../Support/helpers.hpp"

/** Contracts */
#include "../Contracts/Foundation/LoggerContract.hpp"
#include "../Contracts/Support/Facades/Scheduler/EventContract.hpp"
#include "../Contracts/Foundation/BoardContract.hpp"
#include "../Contracts/Gateways/GatewayContract.hpp"
#include "../Contracts/Sensors/DriverContract.hpp"
#include "../Contracts/Sensors/SensorContract.hpp"
#include "../Contracts/Devices/DriverContract.hpp"
#include "../Contracts/Devices/DeviceContract.hpp"
#include "../Contracts/Collections/CollectionContract.hpp"

/** Collections */
#include "../Collections/Collection.hpp"
#include "../Collections/Vector.hpp"

 /** Traits */
#include "../Traits/HasNotification.hpp"
#include "../Traits/HasLogger.hpp"
#include "../Traits/HasId.hpp"

/** Support */
#include "../Support/Facades/Debug.hpp"
#include "../Support/Facades/Fluid.hpp"
#include "../Support/Facades/Scheduler/BaseEvent.hpp"
#include "../Support/Facades/Scheduler/Event.hpp"
#include "../Support/Facades/Scheduler/StaticEvent.hpp"
#include "../Support/Facades/Scheduler/Scheduler.hpp"
#include "../Support/Facades/Route.hpp"

/** Gateways */
#include "../Gateways/Esp8266/WifiHttpClient.hpp"
#include "../Gateways/Esp8266/WifiWebServer.hpp"

/** Sensors */
#include "../Sensors/Drivers/Driver.hpp"
#include "../Sensors/Drivers/GenericDriver.hpp"
#include "../Sensors/Sensor.hpp"

/** Devices */
#include "../Devices/Drivers/Driver.hpp"
#include "../Devices/Drivers/GenericDriver.hpp"
#include "../Devices/Drivers/SinkModeDriver.hpp"
#include "../Devices/Drivers/AirConditionerDriver.hpp"
#include "../Devices/Device.hpp"

/** Foundation */
#include "../Foundation/Logger.hpp"
#include "../Foundation/Board.hpp"
#include "../Foundation/BaseController.hpp"
#include "../Foundation/Application.hpp"