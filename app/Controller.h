namespace App {
using Nugraha::Foundation::BaseController;
using Nugraha::Foundation::Board;

class Controller : public BaseController
{
protected:
    Board* homeAutomation = new Board(1);
    
public:
    /**
     * Inisialisasi board Arduino dan devices.
     */
    void setup()
    {
        int a = 2;
    }

    /**
     * Fungsi yang terus dieksekusi selagi Arduino masih on.
     */
    void loop()
    {
        char* hasil = Fluid::concat(4, "Hello ", "From Fugue!", " How are you?");
        Debug::printFreeMemory();
        Serial.println(strlen(hasil));
        delay(1000);

        delete hasil;
    }
};

}