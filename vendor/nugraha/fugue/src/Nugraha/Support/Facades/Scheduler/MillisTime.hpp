namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

class MillisTime : public virtual DueTimeManager
{
protected:
    unsigned long dueTime;
    unsigned long previousMillis;

public:
    MillisTime(unsigned long dueTime)
    {
        previousMillis = millis();
        this->dueTime = dueTime;
    }

    bool isDueTime()
    {
        unsigned long now = millis();
        if(now - previousMillis >= dueTime) {
            previousMillis = now;
            return true;
        }
        return false;
    }
};

}}}}