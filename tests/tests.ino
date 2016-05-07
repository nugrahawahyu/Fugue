#include "tests.h"
#include "../Fugue.h"
using namespace Nugraha::TugasAkhirWahyu;

Foundation::App test = Foundation::App(0);

void setup()
{
    Serial.begin(9600);
    Debug::println("Hello, this is a test.");
    test.setup();
}

void loop()
{
    test.loop();
}