namespace Nugraha { namespace Collections {
using Nugraha::Collections::Collection;

template <class MembersType>
class Vector : public virtual Collection<MembersType> {
public:
    virtual ~Vector() {}
    void removeAt(int index)
    {
        delete &(this->members[index]);
        this->members.erase(this->members.begin() + index);
    }
};

}}