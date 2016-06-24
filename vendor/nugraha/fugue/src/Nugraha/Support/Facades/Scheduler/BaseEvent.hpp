namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Contracts::Support::Facades::Scheduler::EventContract;
using Nugraha::Traits::HasId;

class BaseEvent : public virtual EventContract, public virtual HasId<int>
{
protected:
    unsigned long interval;
    unsigned long previousMillis;
    int repeatCount = -1;

public:
    BaseEvent(unsigned long interval, int repeatCount)
    {
        this->previousMillis = millis();
        this->interval = interval;
        this->repeatCount = repeatCount;
    }

    virtual ~BaseEvent()
    {
        
    }

    int executionCount = 0;
    void update(unsigned long now)
    {
        if(now - previousMillis >= interval && (repeatCount == -1 || repeatCount > 0)) {
            previousMillis = now;
            Serial.printf("[%d] ", this->id);
            executeCallback();
            if(repeatCount != -1) {
                repeatCount--;
            }
        }
    }

    int getRepeatCount()
    {
        return repeatCount;
    }

    int getId() override
    {
        HasId::getId();
    }
};

}}}}
