namespace Nugraha { namespace Contracts { namespace Collections {

class CollectionContract 
{
public:
    virtual void add()=0;
    virtual void removeAt(int index)=0;
};

}}}