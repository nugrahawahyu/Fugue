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

/** Main app libraries */
#include "../Fugue.h"

/** Test Cases */
#ifdef _FreeMemoryTest
#include "TestCases/FreeMemoryTest.h"
#endif

#ifdef _SchedulerTest
#include "TestCases/SchedulerTest.h"
#endif

#ifdef _JsonTest
#include "TestCases/JsonTest.h"
#endif

#ifdef _UserCommandExecutorTest
#include "TestCases/UserCommandExecutorTest.h"
#endif

#ifdef _SignalStrengthTest
#include "TestCases/SignalStrengthTest.h"
#endif

#ifdef _VectorOfObjectTest
#include "TestCases/VectorOfObjectTest.h"
#endif

namespace Tests { namespace TestCases {} }
using namespace Nugraha::Devices;

