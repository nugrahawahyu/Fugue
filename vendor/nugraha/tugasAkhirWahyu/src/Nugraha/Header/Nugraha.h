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

/** Contracts */
#include "../Contracts/Support/Facades/Scheduler/EventContract.h"
#include "../Contracts/Sensors/DriverContract.h"
#include "../Contracts/Sensors/SensorContract.h"
#include "../Contracts/Devices/DriverContract.h"
#include "../Contracts/Devices/DeviceContract.h"
#include "../Contracts/Collections/CollectionContract.h"

/** Collections */
#include "../Collections/Collection.h"
#include "../Collections/SimpleVector.h"
#include "../Collections/Vector.h"

/** Support */
#include "../Support/Facades/Debug.h"
#include "../Support/Facades/Fluid.h"
#include "../Support/Facades/Scheduler/BaseEvent.h"
#include "../Support/Facades/Scheduler/Event.h"
#include "../Support/Facades/Scheduler/Scheduler.h"

/** Sensors */
#include "../Sensors/Drivers/Driver.h"
#include "../Sensors/Drivers/GenericDriver.h"
#include "../Sensors/Sensor.h"

/** Devices */
#include "../Devices/Drivers/Driver.h"
#include "../Devices/Drivers/GenericDriver.h"
#include "../Devices/Drivers/SinkModeDriver.h"
#include "../Devices/Device.h"

/** Foundation */
#include "../Foundation/Board.h"
#include "../Foundation/BaseController.h"
#include "../Foundation/Application.h"

