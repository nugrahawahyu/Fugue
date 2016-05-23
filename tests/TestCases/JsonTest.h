namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Logger;
using Nugraha::Foundation::BaseController;

class JsonTest : public virtual BaseController
{
public:
    Logger* logger = new Logger();
    void setup(void) 
    {
        Serial.begin(115200);
        logger->addNotification(1, "1");
        logger->addNotification(1, "2");
        logger->addNotification(1, "3");
        logger->addNotification(0, "4");
        logger->addNotification(0, "5");
        logger->addNotification(0, "6");
        logger->addSensorMeasurement("suhu", "33");
        logger->addSensorMeasurement("cahaya", "1");
        String messages = logger->getLogMessage();
        Serial.println(messages);
    }

    void loop() 
    {
/**
{
  "records": [
    {
      "notifications": {
        "turnOn": [
          "4",
          "5",
          "6"
        ],
        "turnOff": [
          "1",
          "2",
          "3"
        ]
      }
    },
    {
      "measurements": [
        {
          "sensor": "suhu",
          "value": "33"
        },
        {
          "sensor": "cahaya",
          "value": "1"
        }
      ]
    }
  ]
}
*/
    }
};

}}