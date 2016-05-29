namespace Nugraha { namespace Collections {
using Nugraha::Contracts::Collections::CollectionContract;

template <class MembersType>
class Collection : public virtual CollectionContract<MembersType> 
{
protected:
    std::vector<MembersType> members;

public:
    virtual ~Collection() {}
    /**
     * Mendapatkan jumlah member dari koleksi members.
     * 
     * @return int - jumlah members
     */
    int count()
    {
        return members.size();
    }

    /**
     * Memnambahkan satu member ke urutan paling belakang 
     * koleksi members.
     * 
     * @param newMember - member baru dengan tipe apa saja.
     */
    void add(MembersType newMember)
    {
        members.push_back(newMember);
    }

    void setMemberAt(int index, MembersType newMember)
    {
        members[index] = newMember;
    }

    /**
     * Menghapus member pada index tertentu.
     * 
     * @param index
     */
    void removeAt(int index)
    {
        members.erase(members.begin() + index);
    }

    /**
     * Mendapatkan member pada index tertentu.
     * 
     * @param  index - index member yang akan di ambil
     * @return - member dengan type MembersType
     */
    MembersType getMemberAt(int index)
    {
        if(index >= 0 && index < members.size()) {
            return members[index];
        } 
        return NULL;
    }

    std::vector<MembersType>& getMembers()
    {
        return members;
    }
};

}}