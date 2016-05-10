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

/** Support */
#include "../Support/Facades/Debug.h"
#include "../Support/Facades/Fluid.h"

/** Contracts */
#include "../Contracts/Sensors/DriverContract.h"
#include "../Contracts/Sensors/SensorContract.h"
#include "../Contracts/Devices/DriverContract.h"
#include "../Contracts/Devices/DeviceContract.h"
#include "../Contracts/Collections/CollectionContract.h"

/** Sensors */
#include "../Sensors/Drivers/Driver.h"
#include "../Sensors/Drivers/GenericDriver.h"
#include "../Sensors/Sensor.h"

/** Devices */
#include "../Devices/Drivers/Driver.h"
#include "../Devices/Drivers/GenericDriver.h"
#include "../Devices/Device.h"

/** Collections */
#include "../Collections/Collection.h"
#include "../Collections/SimpleVector.h"
// #include "../Collections/Vector.h"

/** Foundation */
#include "../Foundation/Board.h"
#include "../Foundation/BaseController.h"
#include "../Foundation/Application.h"

