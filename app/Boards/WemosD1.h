namespace App { namespace Boards { 
using namespace App::Devices;
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
using Nugraha::Foundation::Board;
                
class WemosD1 : public virtual Board {
protected:
    /**
     * Pins:
     * D0  - RX 
     * D1  - TX  
     * D2  - IO 
     * D3  - (D15) IO, SCL 
     * D4  - (D14) IO, SDA
     * D5  - (D13) IO, SCK 
     * D6  - (D12) IO, MISO 
     * D7  - (D11) IO, MOSI 
     * D8  - IO, Pull-up 
     * D9  - IO, Pull-up, BUILTIN_LED 
     * D10 - IO, Pull-down,SS 
     * A0  - Analog Input 
     */
    void devices()
    {
        this->attachDevice(new BlinkingLed(D2, NULL, 1000));
        this->attachDevice(new BlinkingLed(D3, NULL, 1300));
        this->attachDevice(new BlinkingLed(D4, NULL, 1600));
        this->attachDevice(new BlinkingLed(D5, NULL, 1900));
        this->attachDevice(new BlinkingLed(D9, NULL, 2000));
    }

    void sensors(){}
};

}}