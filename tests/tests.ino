#define JsonTest_h
#include "tests.h"
using namespace App::Boards;
using namespace Tests::TestCases;
using Nugraha::Foundation::Application;

Application* test = new Application(new JsonTest(), new WemosD1(), 115200, true);

void setup()
{
    Serial.begin(test->serialBaudRate);
    test->setup();
}

void loop()
{
    test->loop();
}