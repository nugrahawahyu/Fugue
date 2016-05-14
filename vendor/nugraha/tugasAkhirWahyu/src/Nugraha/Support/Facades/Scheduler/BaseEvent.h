namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Contracts::Support::Facades::Scheduler::EventContract;

class BaseEvent : public virtual EventContract
{
protected:
    unsigned long interval;
    unsigned long previousMillis = millis();

public:
    int executionCount = 0;
    void update(unsigned long now)
    {
        if(now - previousMillis >= interval) {
            previousMillis = now;
            executeCallback();
        }
    }
};

}}}}
