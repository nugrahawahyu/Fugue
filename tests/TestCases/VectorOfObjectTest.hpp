namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Logger;
using Nugraha::Collections::Vector;
using Nugraha::Foundation::BaseController;
using Nugraha::Support::Facades::Scheduler::Event;
using Nugraha::Support::Facades::Scheduler::BaseEvent;
using Nugraha::Support::Facades::Scheduler::StaticEvent;
using Nugraha::Contracts::Collections::CollectionContract;

class VectorOfObjectTest : public virtual BaseController
{
protected:
    static CollectionContract<BaseEvent*>* fooCollection;

public:
    VectorOfObjectTest()
    {

    }
    void setup(void) 
    {
        Serial.println(fooCollection->count());
        add([](){});
        Serial.println(fooCollection->count());
        add([](){});
        Serial.println(fooCollection->count());
        add([](){});
        Serial.println(fooCollection->count());
        add([](){});
        Serial.println(fooCollection->count());
        add([](){});
        Serial.println(fooCollection->count());

        int i=0;
        int memberCount = fooCollection->count();

        while(i<memberCount) {
            fooCollection->removeAt(i);
            memberCount = fooCollection->count();
            Serial.println(fooCollection->count());
            i--;
            i++;
        }
    }

    void loop() 
    {
        
    }

    template<typename Callback>
    void add(Callback callback)
    {
        fooCollection->add(new StaticEvent<Callback>(2, callback, -1));
    }
};

CollectionContract<BaseEvent*>* VectorOfObjectTest::fooCollection = new Vector<BaseEvent*>();
}}