#define _SchedulerTest
#include "tests.h"
using namespace App::Boards;
using namespace Tests::TestCases;
using namespace Nugraha::Devices;
using Nugraha::Foundation::Application;

Application* test = new Application(new SchedulerTest(), new Board(), 115200, true);
void setup()
{
    Serial.begin(test->serialBaudRate);
    test->setup();
}

void loop()
{
    test->loop();
}