namespace Nugraha { namespace Contracts { namespace Services {
using Nugraha::Contracts::Foundation::BoardContract;
using Nugraha::Contracts::Foundation::LoggerContract;

class ServiceContract 
{
public:    
    virtual ~ServiceContract() {}
    virtual int getId()=0;
    virtual void service()=0;
    virtual void setLogger(LoggerContract* logger)=0;
    virtual LoggerContract* getLogger()=0;
    virtual void setBoard(BoardContract* board)=0;
};

}}}