#ifndef _Fugue_h_
#define _Fugue_h_

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

/** env */
#include "config/env.hpp"

/** Vendor Libraries */
#include "vendor/vendor.h"
#include "config/kernel.hpp"

/** App */
#include "app/Header/app.h"

#endif