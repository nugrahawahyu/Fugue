namespace Nugraha { namespace Traits {
using Nugraha::Contracts::Foundation::LoggerContract;

class HasLogger
{
protected:
    LoggerContract* logger = NULL;

public:
    virtual ~HasLogger() {}

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