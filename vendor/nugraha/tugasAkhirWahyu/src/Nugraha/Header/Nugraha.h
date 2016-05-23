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
#include "../Support/helpers.h"

/** Contracts */
#include "../Contracts/Foundation/LoggerContract.h"
#include "../Contracts/Support/Facades/Scheduler/EventContract.h"
#include "../Contracts/Gateways/GatewayContract.h"
#include "../Contracts/Sensors/DriverContract.h"
#include "../Contracts/Sensors/SensorContract.h"
#include "../Contracts/Devices/DriverContract.h"
#include "../Contracts/Devices/DeviceContract.h"
#include "../Contracts/Collections/CollectionContract.h"
#include "../Contracts/Foundation/BoardContract.h"

/** Collections */
#include "../Collections/Collection.h"
#include "../Collections/SimpleVector.h"
#include "../Collections/Vector.h"

 /** Traits */
#include "../Traits/HasNotification.h"
#include "../Traits/HasLogger.h"

/** Support */
#include "../Support/Facades/Debug.h"
#include "../Support/Facades/Fluid.h"
#include "../Support/Facades/Scheduler/BaseEvent.h"
#include "../Support/Facades/Scheduler/Event.h"
#include "../Support/Facades/Scheduler/StaticEvent.h"
#include "../Support/Facades/Scheduler/Scheduler.h"
#include "../Support/Facades/Route.h"

/** Gateways */
#include "../Gateways/Esp8266/WifiHttpClient.h"
#include "../Gateways/Esp8266/WifiWebServer.h"

/** Sensors */
#include "../Sensors/Drivers/Driver.h"
#include "../Sensors/Drivers/GenericDriver.h"
#include "../Sensors/Sensor.h"

/** Devices */
#include "../Devices/Drivers/Driver.h"
#include "../Devices/Drivers/GenericDriver.h"
#include "../Devices/Drivers/SinkModeDriver.h"
#include "../Devices/Drivers/AirConditionerDriver.h"
#include "../Devices/Device.h"

/** Foundation */
#include "../Foundation/Logger.h"
#include "../Foundation/Board.h"
#include "../Foundation/BaseController.h"
#include "../Foundation/Application.h"