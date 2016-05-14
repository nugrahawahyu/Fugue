namespace Nugraha { namespace Gateways {
using Nugraha::Contracts::Gateways::GatewayContract;

class Gateway : public virtual GatewayContract
{
protected:
    String dataToSend;

public:
    String publish()
    {

    }
};

}}