#ifndef _bootstrap_h_
#define _bootstrap_h_
using Nugraha::Foundation::Application;
using namespace Main;
using namespace Nugraha::Devices;

#include "../config/config.h"

void printBootMessage()
{
Serial.println((" _       __          __                                "));
Serial.println(("| |     / /  ___    / /  _____  ____    ____ ___   ___ "));
Serial.println(("| | /| / /  / _ \\  / /  / ___/ / __ \\  / __ `__ \\ / _ \\"));
Serial.println(("| |/ |/ /  /  __/ / /  / /__  / /_/ / / / / / / //  __/"));
Serial.println(("|__/|__/   \\___/ /_/   \\___/  \\____/ /_/ /_/ /_/ \\___/ "));
Serial.println(("                   --- MR. Wahyu ---                   "));                                                                                                 
                                                                                                 
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