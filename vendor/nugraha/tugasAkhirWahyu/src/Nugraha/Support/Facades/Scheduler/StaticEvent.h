namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

template<class Callback>
class StaticEvent : public virtual BaseEvent
{
protected:
    Callback callback;
    
public:
    StaticEvent(unsigned long interval, Callback callback) : callback(callback)
    {
        this->interval = interval;
    }

    void executeCallback()
    {
        this->callback();
    }
};

}}}}
