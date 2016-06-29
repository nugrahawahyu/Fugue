namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Contracts::Support::Facades::Scheduler::EventContract;
using Nugraha::Traits::HasId;

class BaseEvent : public virtual EventContract, public virtual HasId<int>
{
protected:
    int repeatCount = -1;
    DueTimeManager* schedule;

public:
    BaseEvent(DueTimeManager* schedule, int repeatCount)
    {
        this->repeatCount = repeatCount;
        this->schedule = schedule;
    }

    virtual ~BaseEvent(){}

    int executionCount = 0;
    void update()
    {
        if(schedule->isDueTime() && (repeatCount == -1 || repeatCount > 0)) {
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
