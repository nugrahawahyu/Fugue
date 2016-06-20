namespace Nugraha { namespace Contracts { namespace Collections {

template <class MembersType>
class CollectionContract 
{
public:
    virtual ~CollectionContract() {}
    virtual void add(MembersType newMember)=0;
    virtual void setMemberAt(int index, MembersType newMember)=0;
    virtual void removeAt(int index)=0;
    virtual int count()=0;
    virtual MembersType getMemberAt(int index)=0;
    virtual std::vector<MembersType>& getMembers()=0;
};

}}}