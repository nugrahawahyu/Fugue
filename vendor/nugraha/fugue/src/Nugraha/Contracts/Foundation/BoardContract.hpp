namespace Nugraha { namespace Contracts { namespace Foundation {

class BoardContract 
{
public:
    virtual ~BoardContract() {}
    virtual void devices()=0;
    virtual void sensors()=0;
    virtual void services()=0;
    virtual void initialize()=0;
    virtual void automate()=0;
    virtual void executeUserCommand(String userCommands)=0;
};

}}}
