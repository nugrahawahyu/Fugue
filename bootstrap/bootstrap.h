#ifndef _bootstrap_h_
#define _bootstrap_h_
using Nugraha::Foundation::Application;
using namespace Main;
using namespace Nugraha::Devices;

#include "../config/config.h"

void printBootMessage()
{
Serial.println(F(" _       __          __                                "));
Serial.println(F("| |     / /  ___    / /  _____  ____    ____ ___   ___ "));
Serial.println(F("| | /| / /  / _ \\  / /  / ___/ / __ \\  / __ `__ \\ / _ \\"));
Serial.println(F("| |/ |/ /  /  __/ / /  / /__  / /_/ / / / / / / //  __/"));
Serial.println(F("|__/|__/   \\___/ /_/   \\___/  \\____/ /_/ /_/ /_/ \\___/ "));
Serial.println(F("                   --- MR. Wahyu ---                   "));                                                                                                 
                                                                                                 
}

void setup()
{
    Debug::isDebugMode = true;
    if(application->beginSerial)
        Serial.begin(application->serialBaudRate);
    printBootMessage();
    application->setup();
}

void loop()
{ 
    application->loop(); 
}


#endif