namespace Nugraha { namespace Contracts { namespace Gateways {

class GatewayContract 
{
public:
    virtual void initialize()=0;
    virtual void service()=0;
};

}}}
