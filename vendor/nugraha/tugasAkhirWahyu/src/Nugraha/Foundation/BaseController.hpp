namespace Nugraha { namespace Foundation {
using Nugraha::Contracts::Foundation::BoardContract;

class BaseController 
{
public:
    BoardContract* board;
    virtual ~BaseController() {}
    virtual void setup()=0;
    virtual void loop()=0;
};

}}