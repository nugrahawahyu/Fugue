namespace Nugraha { namespace Collections {
using Nugraha::Collections::Collection;

template <class MembersType>
class Vector : public virtual Collection<MembersType> {
public:
    virtual ~Vector() {}
    void removeAt(int index)
    {
        Serial.printf("Deleting member...");
        delete &(this->members[index]);
        Serial.printf("Berhasil medelete Object...");
        this->members.erase(this->members.begin() + index);
        Serial.println("berhasil di delete dari list!!!!!!!!!");
    }
};

}}