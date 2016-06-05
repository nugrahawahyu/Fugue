#define _AllTests
#include "tests.h"
using namespace App::Boards;
using namespace Tests::TestCases;
using Nugraha::Foundation::Application;

Application* test = new Application(new PingTest(), new WemosD1(), 115200, true);

void setup()
{
    Serial.begin(test->serialBaudRate);
    test->setup();
}

void loop()
{
    test->loop();
}