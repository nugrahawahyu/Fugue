namespace Nugraha { namespace Traits {
using Nugraha::Contracts::Foundation::LoggerContract;

template<class T>
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

template<class T>
int HasId<T>::ID = 0;
}}