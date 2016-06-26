namespace Nugraha { namespace Traits {

template<class MyClass>
class RecordableInstance
{
protected:
    static std::vector<MyClass> myInstances;

public:
    virtual ~RecordableInstance() {}

    static std::vector<MyClass> all()
    {
        return myInstances;
    }

    static MyClass wherePin(int pin)
    {
        for (int i=0; i<myInstances.size(); i++)
        {
            if(myInstances[i] != NULL) {
                if(myInstances[i]->getPin() == pin)
                    return myInstances[i];
            }
        }
        return NULL;
    }

    static MyClass whereIndex(int index)
    {
        return myInstances[index];
    }
};
template<class MyClass>
std::vector<MyClass> RecordableInstance<MyClass>::myInstances = std::vector<MyClass>();

}}