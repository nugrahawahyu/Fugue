namespace Nugraha { namespace Contracts { namespace Services {
using Nugraha::Foundation::Logger;
using Nugraha::Contracts::Foundation::BoardContract;

class ServiceContract 
{
public:    
    virtual ~ServiceContract() {}
    virtual int getId()=0;
    virtual void service()=0;
    virtual void setLogger(Logger* logger)=0;
    virtual Logger* getLogger()=0;
    virtual void setBoard(BoardContract* board)=0;
};

}}}