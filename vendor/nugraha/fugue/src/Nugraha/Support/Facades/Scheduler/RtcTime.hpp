namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {

class RtcTime : public virtual DueTimeManager
{
protected:
    DateTime dueTime;
    TimeSpan interval;
    static RTC_DS1307 rtc;

public:
    RtcTime(DateTime dueTime)
    {
        interval = dueTime - rtc.now();
        this->dueTime = dueTime;
    }

    RtcTime(TimeSpan interval)
    {
        this->interval = interval;
        this->dueTime =  DateTime(rtc.now() + interval);
    }

    bool isDueTime()
    {
        DateTime now = rtc.now();
        if(now.unixtime() >= dueTime.unixtime()) {
            dueTime = DateTime(now + interval);
            return true;
        }
        return false;
    }
};

}}}}