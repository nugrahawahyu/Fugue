namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Collections::Collection;
using Nugraha::Contracts::Collections::CollectionContract;

class Scheduler
{
protected:
    static std::vector<BaseEvent*> eventCollection;
    static bool isFirstRun;

public:
    /**
     * Method yang akan mengecek setiap event apakah callback-nya harus dieksekusi
     * atau tidak.
     */
    static void handleEvents()
    {
        if(isFirstRun) {
            after(1, [=](){Serial.println();});
            isFirstRun = false;
        }

        for(auto event = eventCollection.begin(); event != eventCollection.end();) {
            (*event)->update();
            if((*event)->getRepeatCount() == 0) {
                delete *event;
                *event = NULL;
                event = eventCollection.erase(event);
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
    static void every(unsigned long schedule, Callback callback, int repeatCount = -1)
    {
        eventCollection.push_back(new StaticEvent<Callback>(Millis(schedule), callback, repeatCount));
    }

    template<typename Callback>
    static void every(DueTimeManager* schedule, Callback callback, int repeatCount = -1)
    {
        eventCollection.push_back(new StaticEvent<Callback>(schedule, callback, repeatCount));
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
    static void every(unsigned long schedule, ObjectType object, Callback callback, int repeatCount = -1)
    {
        eventCollection.push_back(new Event<Callback, ObjectType>(new MillisTime(schedule), callback, object, repeatCount));
    }

    template<typename Callback, typename ObjectType>
    static void every(DueTimeManager* schedule, ObjectType object, Callback callback, int repeatCount = -1)
    {
        eventCollection.push_back(new Event<Callback, ObjectType>(schedule, callback, object, repeatCount));
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
        return eventCollection[index];
    }
};

std::vector<BaseEvent*> Scheduler::eventCollection = std::vector<BaseEvent*>();
bool Scheduler::isFirstRun = true;

}}}}
