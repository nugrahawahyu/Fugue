namespace App { namespace Sensors {
using Nugraha::Sensors::Sensor;

class Ds18B20 : public virtual Sensor
{
public:
    static OneWire* oneWire;
    static DallasTemperature* sensors;
    bool isFirstInstance = true;

    Ds18B20(const int ONE_WIRE_BUS) : Sensor(ONE_WIRE_BUS)
    {
        if(isFirstInstance) {
            oneWire = new OneWire(ONE_WIRE_BUS);
            sensors = new DallasTemperature(oneWire);
            isFirstInstance = false;
        }
        sensors->begin();
    }

    double readMeasurementValue()
    {
        Debug::print("Requesting temperatures...");
        sensors->requestTemperatures();
        Debug::println("DONE");

        return sensors->getTempCByIndex(0);
    }
};

OneWire* Ds18B20::oneWire = NULL;
DallasTemperature* Ds18B20::sensors = NULL;

}}