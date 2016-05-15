/** Libraries */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <vector>
#include "Timer.h"

/** External libraries */
#include <ArduinoJson.h>

/** Main app libraries */
#include "../Fugue.h"

/** Test Cases */
#ifdef FreeMemoryTest_h
#include "TestCases/FreeMemoryTest.h"
#endif

#ifdef TimerTest_h
#include "TestCases/TimerTest.h"
#endif

#ifdef SchedulerTest_h
#include "TestCases/SchedulerTest.h"
#endif

namespace Tests { namespace TestCases {} }
using namespace Nugraha::Devices;
DriverContract* Device::defaultDriver = new Drivers::SinkModeDriver();
