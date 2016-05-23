namespace Nugraha { namespace Foundation {
using Nugraha::Contracts::Foundation::LoggerContract;

class Logger : public LoggerContract {
protected:
        DynamicJsonBuffer jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();
        JsonArray& records = root.createNestedArray("records");
        JsonObject& records_notifications = records.createNestedObject().createNestedObject("notifications");
        JsonArray& records_notifications_turnOn = records_notifications.createNestedArray("turnOn");
        JsonArray& records_notifications_turnOff = records_notifications.createNestedArray("turnOff");
        JsonArray& records_measurements = records.createNestedObject().createNestedArray("measurements");

public:
    void addNotification(int code, String message)
    {
        switch(code) {
        case 0 : 
            records_notifications_turnOff.add(message);
            break;
        case 1 : 
            records_notifications_turnOn.add(message);
            break;
        default : 
            break;
        }
    }

    void addSensorMeasurement(String sensorName, String measurementValue)
    {
        JsonObject& measurement = records_measurements.createNestedObject();
        measurement["sensor"] = sensorName;
        measurement["value"] = measurementValue;
    }

    String getLogMessage()
    {
        String logMessages;
        root.printTo(logMessages);
        return logMessages;
    }

    void printToSerial()
    {
        root.prettyPrintTo(Serial);
    }
};

}}