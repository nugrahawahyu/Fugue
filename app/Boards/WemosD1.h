namespace App { namespace Boards { 
using namespace App::Devices;
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
using Nugraha::Foundation::Board;
                
class WemosD1 : public virtual Board {
protected:
    void devices()
    {
        /** D0  - RX */
        this->attachDevice(Default);

        /** D1  - TX  */
        this->attachDevice(Default);

        /** D2  - IO */
        this->attachDevice(new BlinkingLed(D2, NULL, 1000));

        /** D3  - (D15) IO, SCL */
        this->attachDevice(new BlinkingLed(D3, NULL, 1300));

        /** D4  - (D14) IO, SDA*/
        this->attachDevice(new BlinkingLed(D4, NULL, 1600));

        /** D5  - (D13) IO, SCK */
        this->attachDevice(new BlinkingLed(D5, NULL, 1900));

        /** D6  - (D12) IO, MISO */
        this->attachDevice(Default);

        /** D7  - (D11) IO, MOSI */
        this->attachDevice(Default);

        /** D8  - IO, Pull-up */
        this->attachDevice(Default);

        /** D9  - IO, Pull-up, BUILTIN_LED */
        this->attachDevice(new Led(D9, NULL));

        /** D10 - IO, Pull-down,SS */
        this->attachDevice(Default);

        /** A0  - Analog Input */
        this->attachDevice(Default);
    }

    void sensors(){}
};

}}