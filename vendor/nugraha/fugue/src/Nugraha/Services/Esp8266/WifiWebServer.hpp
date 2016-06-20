namespace Nugraha { namespace Services { namespace Esp8266 {
using Nugraha::Traits::HasLogger;
using Nugraha::Contracts::Services::ServiceContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class WifiWebServer : public virtual ServiceContract, public HasLogger
{
protected:
    String message;
    
public:
    virtual ~WifiWebServer() {}
    
    void setMessage(String message)
    {
        this->message = message;
    }
    
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