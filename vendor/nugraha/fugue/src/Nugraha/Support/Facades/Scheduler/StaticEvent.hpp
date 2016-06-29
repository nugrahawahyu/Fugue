namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

template<class Callback>
class StaticEvent : public virtual BaseEvent
{
protected:
    Callback callback;
    
public:
    StaticEvent(DueTimeManager* schedule, Callback callback, int repeatCount) : BaseEvent(schedule, repeatCount), callback(callback)
    {
        
    }

    void executeCallback()
    {
        this->callback();
    }
};

}}}}
