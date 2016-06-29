/** Built-in Libraries */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <vector>
#include <map>
#include <Wire.h>

/** Third-party libraries */
#include "OneWire.h"
#include "RTClib.h"

/** Fugue */
#include "../fugue.h"

/** Test Cases */
#include "TestCases/header/TestCases.h"