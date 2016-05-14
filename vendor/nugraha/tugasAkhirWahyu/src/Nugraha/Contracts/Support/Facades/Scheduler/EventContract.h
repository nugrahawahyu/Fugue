namespace Nugraha { namespace Contracts { namespace Support { namespace Facades { namespace Scheduler {

class EventContract
{
public:
    virtual void update(unsigned long now)=0;
    virtual void executeCallback()=0;
};

}}}}}