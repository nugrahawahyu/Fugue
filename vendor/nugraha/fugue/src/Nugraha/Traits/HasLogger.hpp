namespace Nugraha { namespace Traits {
using Nugraha::Foundation::Logger;

class HasLogger
{
protected:
    Logger* logger = NULL;

public:
    virtual ~HasLogger() {}

    void setLogger(Logger* logger)
    {
        this->logger = logger;
    }

    Logger* getLogger()
    {
        return this->logger;
    }

};

}}