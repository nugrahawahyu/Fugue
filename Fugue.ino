/**
 * TugasAkhirWahyu - Sebuah program Arduino untuk Home Automation.
 *
 * @package TugasAkhirWahyu
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>
 */
#include "Fugue.h"

void setup()
{
    Debug::isDebugMode = true;
    Serial.begin(9600);
    Serial.println(F("+---------------------------------------------+"));
    Serial.println(F("|                     Fugue                   |"));
    Serial.println(F("+---------------------------------------------+"));
    controller.setup();
}

void loop()
{ 
    controller.loop(); 
}