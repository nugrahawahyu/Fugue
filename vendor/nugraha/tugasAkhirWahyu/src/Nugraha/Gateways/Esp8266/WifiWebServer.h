namespace Nugraha { namespace Gateways { namespace Esp8266 {
using Nugraha::Traits::HasLogger;
using Nugraha::Contracts::Gateways::GatewayContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class WifiWebServer : public virtual GatewayContract, public HasLogger
{
public:
    void setLogger(LoggerContract* logger) override
    {
        HasLogger::setLogger(logger);
    }

    LoggerContract* getLogger() override
    {
        HasLogger::getLogger();
    }
};

}}}