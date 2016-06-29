namespace Nugraha { namespace Contracts { namespace Support { namespace Facades { namespace Scheduler {

class TimeContract
{
public:
    virtual ~TimeContract(){}
    virtual bool isDueTime()=0;
};

}}}}}