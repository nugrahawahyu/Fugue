namespace Tests { namespace TestCases {
using App::Sensors::Ds18B20;
using Nugraha::Foundation::BaseController;

class Ds18B20Test : public virtual BaseController
{
protected:
    Ds18B20* temperatureSensor = new Ds18B20(D6);

public:
    void setup(void) 
    {
        Scheduler::every(1000, [=]() {
            Serial.println(temperatureSensor->readMeasurementValue());
        });
    }

    void loop() 
    {
        Scheduler::handleEvents();
    }
};

}}