namespace App { namespace Devices { 
using Nugraha::Sensors::Sensor;
using Nugraha::Devices::Device;

class BlinkingLed : public Led
{
public:
    long interval = 2000;

    BlinkingLed(int pin, Sensor* sensor=NULL, long interval=2000) : Led(pin, sensor), Device(pin, sensor)
    {
        this->interval = interval;
    }

    void behavior()
    {
        unsigned long currentMillis = millis();
        if(currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            if (this->isOn==false) {
                Debug::println("Hidupkan");
                this->turnOn();
            }
            else {
                Debug::println("Matikan");
                this->turnOff();
            }
        }
    }
};

}}