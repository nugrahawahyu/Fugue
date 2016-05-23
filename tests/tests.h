/** Libraries */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <vector>
#include <map>

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

#ifdef JsonTest_h
#include "TestCases/JsonTest.h"
#endif

namespace Tests { namespace TestCases {} }
using namespace Nugraha::Devices;

