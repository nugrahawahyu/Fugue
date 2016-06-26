namespace App { namespace Services {
using Nugraha::Sensors::Sensor;
using Nugraha::Services::Service;

class TemperatureLogger : public virtual Service
{
protected:
    unsigned long interval = 3000;
    double temperature;

public:
    void service()
    {
        Scheduler::every(interval, [=]() {
            updateTemperature();
        });
    }

    void updateTemperature()
    {
        temperature = Sensor::whereIndex(0)->readMeasurementValue();
        logger->addRecord("Measurement", "sensor", "DS18B20 Temperature Sensor", "value", temperature);
    }
};

}}