namespace Nugraha { namespace Gateways {
using Nugraha::Contracts::Gateways::GatewayContract;
using Nugraha::Contracts::Devices::DeviceContract;

class Gateway : public virtual GatewayContract, public virtual DeviceContract
{
protected:
    String dataToSend;

public:
    String publish()
    {

    }
};

}}