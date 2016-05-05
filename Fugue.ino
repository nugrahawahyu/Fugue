/**
 * -----------------------------------------------------------------+
 * TugasAkhirWahyu - Sebuah program Arduino untuk Home Automation.  |
 *                                                                  |
 * @package TugasAkhirWahyu                                         |
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>               |
 * -----------------------------------------------------------------+
 */
#include "bootstrap/Fugue.h"

void setup()
{
    controller->setup();
}

void loop()
{
    controller->loop();
}