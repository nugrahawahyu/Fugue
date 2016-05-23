namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Collections::Vector;
using Nugraha::Collections::Collection;

class Scheduler 
{
protected:
    static Collection<BaseEvent*>* EventCollection;

public:

    /**
     * Method untuk men-register-kan sebuah event yang akan mengeksekusi callback
     * fungsi statis yang diberikan padanya dengan interval yang diberikan.
     *
     * @param int interval       - interval callback akan dieksekusi.
     * @param callback reference - reference fungsi static.
     */
    template<typename Callback>
    static void every(unsigned long interval, Callback callback, int repeatCount = -1)
    {
        EventCollection->add(new StaticEvent<Callback>(interval, callback));
    }

    /**
     * Method untuk men-register-kan sebuah event yang akan mengeksekusi callback
     * member function yang diberikan padanya dengan interval yang diberikan.
     *
     * @param int interval       - interval callback akan dieksekusi.
     * @param reference object   - reference object yang yang mempunya method pada argument ke 3.
     * @param reference callback - reference fungsi static.
     */
    template<typename Callback, typename ObjectType>
    static void every(unsigned long interval, ObjectType object, Callback callback, int repeatCount = -1)
    {
        EventCollection->add(new Event<Callback, ObjectType>(interval, callback, object));
    }

    /**
     * Method yang akan mengecek setiap event apakah callback-nya harus dieksekusi
     * atau tidak.
     */
    static void handleEvents()
    {
        for(int i=0; i<EventCollection->count(); i++)
        {
            EventCollection->getMemberAt(i)->update(millis());
        }
    }
};

Collection<BaseEvent*>* Scheduler::EventCollection = new Vector<BaseEvent*>();
}}}}
