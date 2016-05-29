namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Collections::Collection;
using Nugraha::Contracts::Collections::CollectionContract;

class Scheduler 
{
protected:
    static CollectionContract<BaseEvent*>* eventCollection;
    static bool init;

public:
    /**
     * Method yang akan mengecek setiap event apakah callback-nya harus dieksekusi
     * atau tidak.
     */
    static void handleEvents()
    {
        if(init) {
            after(1, [=](){});
            init = false;
        }

        for(auto event = eventCollection->getMembers().begin(); event != eventCollection->getMembers().end();) {
            (*event)->update(millis());
            if((*event)->getRepeatCount() == 0) {
                Serial.println(eventCollection->count());
                Serial.println("Habis, Deleting Event...");
                Serial.printf("getFreeHeap: %08d\n", ESP.getFreeHeap());
                delete *event;
                *event = NULL;
                event = eventCollection->getMembers().erase(event);
                Serial.printf("getFreeHeap: %08d\n", ESP.getFreeHeap());
                Serial.println("Event berhasil di delete!!!!!!!!!");
                Serial.println(eventCollection->count());
            } else {
                ++event;
            }
        }
    }

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
        eventCollection->add(new StaticEvent<Callback>(interval, callback, repeatCount));
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
        eventCollection->add(new Event<Callback, ObjectType>(interval, callback, object, repeatCount));
    }

    /**
     * Method untuk men-register-kan event yang akan dieksekusi setelah mili detik yang ditentukan
     */
    template<typename Callback>
    static void after(unsigned long afterMillis, Callback callback)
    {
        every(afterMillis, callback, 1);
    }


    static BaseEvent* getEventAt(int index)
    {
        return eventCollection->getMemberAt(index);
    }
};

CollectionContract<BaseEvent*>* Scheduler::eventCollection = new Collection<BaseEvent*>();
bool Scheduler::init = true;

}}}}
