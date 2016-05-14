namespace Nugraha { namespace Support { namespace Facades { namespace Scheduler {
using Nugraha::Contracts::Support::Facades::Scheduler::EventContract;

class BaseEvent : public virtual EventContract
{
public:
    int executionCount = 0;

};

}}}}
