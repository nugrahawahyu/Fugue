#include "tests.h"
using Nugraha::Foundation::Application;
using namespace Tests;

Application* test = new Application(new InheritanceTest());


void setup()
{
    Serial.begin(9600);
    Debug::println(F("|#############[ TEST ]#############|"));
    test->setup();
}

void loop()
{
    test->loop();
}