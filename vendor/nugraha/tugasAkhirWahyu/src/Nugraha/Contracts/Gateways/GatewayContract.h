namespace Nugraha { namespace Contracts { namespace Gateways {

class GatewayContract 
{
public:
    virtual void initialize()=0;
    virtual void runService()=0;
    virtual String publish(String dataJSON)=0;
};

}}}
