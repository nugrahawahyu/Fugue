namespace Nugraha { namespace Contracts { namespace Gateways {
using Nugraha::Contracts::Foundation::LoggerContract;

class GatewayContract 
{
public:
    virtual void initialize()=0;
    virtual void service()=0;
    virtual void setMessage(String message)=0;
    virtual void setLogger(LoggerContract* logger)=0;
    virtual LoggerContract* getLogger()=0;
};

}}}