namespace Nugraha { namespace Traits {
using Nugraha::Contracts::Foundation::LoggerContract;

class HasLogger
{
protected:
    LoggerContract* logger;

public:
    void setLogger(LoggerContract* logger)
    {
        this->logger = logger;
    }

    LoggerContract* getLogger()
    {
        return this->logger;
    }

};

}}