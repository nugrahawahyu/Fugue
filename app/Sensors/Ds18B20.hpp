namespace App { namespace Sensors {
using Nugraha::Sensors::Sensor;

class Ds18B20 : public virtual Sensor
{
public:
    OneWire oneWire(ONE_WIRE_BUS);
    DallasTemperature sensors(&oneWire);

    Ds18B20(const int ONE_WIRE_BUS) : Sensor(ONE_WIRE_BUS)
    {
        sensors.begin();
    }

    double readMeasurementValue()
    {
        Debug::print("Requesting temperatures...");
        sensors.requestTemperatures();
        Debug::println("DONE");

        return sensors.getTempCByIndex(0);
    }
};

}}