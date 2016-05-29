namespace Nugraha { namespace Traits {
using Nugraha::Contracts::Foundation::LoggerContract;

class HasId
{
protected:
    int id;
    static int ID;

public:
    HasId()
    {
        this->id = ID;
        ID++;
    }
    
    virtual ~HasId() {}

    int getId()
    {
        return this->id;
    }
};

int HasId::ID = 0;
}}