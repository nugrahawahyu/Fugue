#ifndef _bootstrap_h_
#define _bootstrap_h_


void printBootMessage()
{
    Serial.println(F("+---------------------------------------------+"));
    Serial.println(F("|                     Fugue                   |"));
    Serial.println(F("+---------------------------------------------+"));   
}

void setup()
{
    Debug::isDebugMode = true;
    Serial.begin(9600);
    printBootMessage();
    controller->setup();
}

void loop()
{ 
    controller->loop(); 
}


#endif