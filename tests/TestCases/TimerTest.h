namespace Tests { namespace TestCases { 
using App::Boards::Arduino;
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;

class TimerTest : public virtual BaseController
{
public:
    Timer t;
    int ledEvent;

    void doSomething()
    {
        Serial.print("2 second tick: millis()=");
        Serial.println(millis());
    }


    void doAfter()
    {
        Serial.println("stop the led event");
        t.stop(ledEvent);
        t.oscillate(13, 500, HIGH, 5);
    }

    void setup()
    {
        Serial.begin(9600);
        int tickEvent = t.every(2000, &TimerTest::doSomething);
        Serial.print("2 second tick started id=");
        Serial.println(tickEvent);
        
        pinMode(13, OUTPUT);
        ledEvent = t.oscillate(13, 50, HIGH);
        Serial.print("LED event started id=");
        Serial.println(ledEvent);
        
        // int afterEvent = t.after(10000, [=]{return this->doAfter();});
        // Serial.print("After event started id=");
        // Serial.println(afterEvent); 
    }

    void loop()
    {
        t.update();
    }

};

}}