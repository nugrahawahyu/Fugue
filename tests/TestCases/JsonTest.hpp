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
        String messages = logger->getLogMessage();
        Serial.println(messages);
        i++;
    }

    void setup(void) 
    {

    }

    void loop() 
    {
        if(i<1) {
            generateMessage();
        }
    }
};

}}