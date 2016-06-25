namespace Nugraha { namespace Services { namespace Esp8266 {
using Nugraha::Traits::HasLogger;
using Nugraha::Services::Service;
using Nugraha::Contracts::Services::ServiceContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class WifiWebServer : public virtual Service
{
protected:
    String message;
    
public:
    virtual ~WifiWebServer() {}
    
    void setMessage(String message)
    {
        this->message = message;
    }
};

}}}