namespace Nugraha { namespace Contracts { namespace Foundation {

class BoardContract 
{
public:
    virtual void devices()=0;
    virtual void sensors()=0;
    virtual void gateways()=0;
    virtual void initialize()=0;
    virtual void automate()=0;
    virtual void executeUserCommand(String userCommands)=0;
};

}}}
