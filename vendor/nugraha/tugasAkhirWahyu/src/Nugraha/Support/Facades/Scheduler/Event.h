namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

template<class Callback>
class Event : public virtual BaseEvent
{
protected:
    int executionCount = 0;
    unsigned long interval;
    unsigned long previousMillis = millis();
    Callback callback;

public:
    Event(unsigned long interval, Callback callback)
    {
        this->interval = interval;
        this->callback = callback;
    }

    void executeCallback()
    {
        this->callback();
    }

    void update(unsigned long now)
    {
        if(now - previousMillis >= interval) {
            previousMillis = now;
            executeCallback();
        }
    }
};

}}}}
