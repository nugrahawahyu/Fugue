namespace Nugraha { namespace Contracts { namespace Support { namespace Facades { namespace Scheduler {

class EventContract
{
public:
    virtual ~EventContract(){}
    virtual void update(unsigned long now)=0;
    virtual void executeCallback()=0;
    virtual int getRepeatCount()=0;
    virtual int getId()=0;
};

}}}}}