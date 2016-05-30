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
#include <ESP8266Ping.h>

/** Main app libraries */
#include "../Fugue.hpp"

/** Test Cases */
#ifdef _FreeMemoryTest
#include "TestCases/FreeMemoryTest.hpp
#endif

#ifdef _SchedulerTest
#include "TestCases/SchedulerTest.hpp
#endif

#ifdef _JsonTest
#include "TestCases/JsonTest.hpp
#endif

#ifdef _UserCommandExecutorTest
#include "TestCases/UserCommandExecutorTest.hpp
#endif

#ifdef _SignalStrengthTest
#include "TestCases/SignalStrengthTest.hpp
#endif

#ifdef _VectorOfObjectTest
#include "TestCases/VectorOfObjectTest.hpp
#endif

#ifdef _PingTest
#include "TestCases/PingTest.hpp
#endif

namespace Tests { namespace TestCases {} }
using namespace Nugraha::Devices;

