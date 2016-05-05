namespace App {
using Nugraha::TugasAkhirWahyu::Foundation::BaseController;
using Nugraha::TugasAkhirWahyu::Foundation::Board;

/**
 * Class untuk mengendalikan board Arduino.
 * 
 * @package TugasAkhirWahyu
 * @Author  Wahyu Nugraha <nugraha.c.wahyu@gmail.com>
 */
class Controller : public BaseController 
{
protected:
    Board* homeAutomation = new Board();

public:
    /**
     * Inisialisasi board Arduino dan devices.
     */
    void setup()
    {
        Serial.begin(9600);
        Serial.println(F("~Fugue~"));
    }

    /**
     * Fungsi yang terus dieksekusi selagi Arduino masih on.
     */
    void loop()
    {
        Debug::printFreeMemory();
        char* hasil = Fluid::concat(Fluid::baseArg+3, "Hello ", "From Fugue!", " How are you?");
        Serial.println(hasil);
        delete hasil;
        delay(1000);
    }
};

}