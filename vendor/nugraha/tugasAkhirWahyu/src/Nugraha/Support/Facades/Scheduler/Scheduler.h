namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Collections::Vector;
using Nugraha::Collections::Collection;

class Scheduler 
{
protected:
    static Collection<BaseEvent*>* EventCollection;

public:

    template<typename Callback>
    static void every(int interval, Callback callback)
    {
        EventCollection->add(new Event<Callback>(interval, callback));
    }

    static void update()
    {
        unsigned long now = millis();
        for(int i=0; i<EventCollection->count(); i++)
        {
            EventCollection->getMemberAt(i)->update(now);
        }
    }
};
Collection<BaseEvent*>* Scheduler::EventCollection = new Vector<BaseEvent*>();
}}}}
