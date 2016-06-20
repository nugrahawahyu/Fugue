#ifndef _bootstrap_h_
#define _bootstrap_h_

using namespace Main;
using namespace App::Boards;
using Nugraha::Foundation::Application;
using Nugraha::Contracts::Devices::DriverContract;

#include "../config/application.hpp"

class Bootstrap {
protected:
    static void printBootMessage()
    {
        Serial.println(F(" _       __          __                                "));
        Serial.println(F("| |     / /  ___    / /  _____  ____    ____ ___   ___ "));
        Serial.println(F("| | /| / /  / _ \\  / /  / ___/ / __ \\  / __ `__ \\ / _ \\"));
        Serial.println(F("| |/ |/ /  /  __/ / /  / /__  / /_/ / / / / / / //  __/"));
        Serial.println(F("|__/|__/   \\___/ /_/   \\___/  \\____/ /_/ /_/ /_/ \\___/ "));
        Serial.println(F("                   --- MR. Wahyu ---                   "));
    }

public:
    static void setup()
    {
        Debug::isDebugMode = true;
        if(application->beginSerial)
            Serial.begin(application->serialBaudRate);
        printBootMessage();
        application->setup();
    }

    static void loop()
    { 
        application->loop(); 
    }
};

void setup() {Bootstrap::setup();}
void loop() {Bootstrap::loop();}

#endif