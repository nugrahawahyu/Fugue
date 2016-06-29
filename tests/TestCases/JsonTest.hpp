namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Logger;
using Nugraha::Foundation::BaseController;

class JsonTest : public virtual BaseController
{
protected:

public:
    Logger* logger = new Logger();
    int i=0;

    void generateMessage()
    {
        logger->printToSerial();
        i++;
    }

    void setup(void) 
    {
        logger->addNotification(1, true);
        logger->addNotification(2, false);
        logger->addNotification(3, true);
        logger->addConnectionInfo("delay", "200");
        logger->addConnectionInfo("packet loss", "2");
        logger->addSensorMeasurement("suhu", 37.5);
        logger->addSensorMeasurement("tekanan", 20);
    }

    void loop() 
    {
        if(i<10) {
            Debug::printFreeMemory();
            generateMessage();
            Debug::printFreeMemory();
        }
    }
};

}}