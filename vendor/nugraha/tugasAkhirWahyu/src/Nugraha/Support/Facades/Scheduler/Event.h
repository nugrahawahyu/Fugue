namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

class Foo{};
template<class Callback, class ObjectType = Foo*>
class Event : public virtual BaseEvent
{
protected:
    int executionCount = 0;
    unsigned long interval;
    unsigned long previousMillis = millis();
    Callback callback;
    ObjectType object = NULL;

public:
    Event(unsigned long interval, Callback callback, ObjectType object = NULL)
    {
        this->interval = interval;
        this->callback = callback;
        this->object   = object;
    }

    void executeCallback()
    {
       ((this->object)->*(this->callback))();
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
