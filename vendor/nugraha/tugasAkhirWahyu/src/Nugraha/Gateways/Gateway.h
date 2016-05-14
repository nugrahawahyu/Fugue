namespace Nugraha { namespace Devices {
using Nugraha::Contracts::Devices::GatewayContract;

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