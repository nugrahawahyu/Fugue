unsigned long hour(unsigned long hour)
{
    return hour * 60 * 60 * 1000;
}

unsigned long minute(unsigned long minute)
{
    return minute * 60 * 1000;
}

Nugraha::Support::Facades::Scheduler::DueTimeManager* Millis(unsigned long time)
{
    return new Nugraha::Support::Facades::Scheduler::MillisTime(time);
}

template<typename TimeType>
Nugraha::Support::Facades::Scheduler::DueTimeManager* Rtc(TimeType time)
{
    return new Nugraha::Support::Facades::Scheduler::RtcTime(time);
}