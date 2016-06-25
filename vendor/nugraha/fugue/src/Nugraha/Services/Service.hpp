namespace Nugraha { namespace Services {
using Nugraha::Traits::HasId;
using Nugraha::Traits::HasLogger;
using Nugraha::Traits::RecordableInstance;
using Nugraha::Contracts::Services::ServiceContract;
using Nugraha::Contracts::Foundation::BoardContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class Service : public virtual ServiceContract, public HasLogger, public HasId<int>, public RecordableInstance<Service*>
{
protected:
    BoardContract* board;
    
public:
    int getId() override {HasId::getId();}
    
    void setLogger(LoggerContract* logger) override
    {
        HasLogger::setLogger(logger);
        // addDelayToRecord(String(0));
    }

    LoggerContract* getLogger()
    {
        return logger;
    }

    void setBoard(BoardContract* board)
    {
        this->board = board;
    }
};

}}