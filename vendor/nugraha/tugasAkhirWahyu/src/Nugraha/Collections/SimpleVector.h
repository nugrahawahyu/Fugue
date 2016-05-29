namespace Nugraha { namespace Collections {
using Nugraha::Collections::Collection;

template <class MembersType>
class SimpleVector : public virtual Collection<MembersType> {
protected:
    MembersType* members;

public:
    virtual ~SimpleVector() {}
    /**
     * Mendapatkan jumlah member dari koleksi members.
     * 
     * @return int - jumlah members
     */
    int count()
    {
    }

    /**
     * Memnambahkan satu member ke urutan paling belakang 
     * koleksi members.
     * 
     * @param newMember - member baru dengan tipe apa saja.
     */
    void add(MembersType newMember)
    {
    }

    /**
     * Menghapus member pada index tertentu.
     * 
     * @param index
     */
    void removeAt(int index)
    {
        
    }

    /**
     * Mendapatkan member pada index tertentu.
     * 
     * @param  index - index member yang akan di ambil
     * @return - member dengan type MembersType
     */
    MembersType getMemberAt(int index)
    {
        return members[index];
    }
};
}}