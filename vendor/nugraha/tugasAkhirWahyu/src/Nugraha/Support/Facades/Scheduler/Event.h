namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

template<class Callback, class ObjectType>
class Event : public virtual BaseEvent
{
protected:
    Callback callback;
    ObjectType object;

public:
    Event(unsigned long interval, Callback callback, ObjectType object)
    {
        this->interval = interval;
        this->callback = callback;
        this->object   = object;
    }

    void executeCallback()
    {
       ((this->object)->*(this->callback))();
    }
};

}}}}
