namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

template<class Callback>
class StaticEvent : public virtual BaseEvent
{
protected:
    Callback callback;
    
public:
    StaticEvent(unsigned long interval, Callback callback, int repeatCount) : BaseEvent(interval, repeatCount), callback(callback)
    {
        
    }

    void executeCallback()
    {
        this->callback();
    }
};

}}}}
