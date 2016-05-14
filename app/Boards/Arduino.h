namespace App { namespace Boards { 
using namespace App::Devices;
using namespace App::Gateways;
using Nugraha::Devices::Device;
using Nugraha::Sensors::Sensor;
using Nugraha::Foundation::Board;
using Nugraha::Devices::Drivers::GenericDriver;

class Arduino : public virtual Board {
protected:
    
    void gateways()
    {
        
    }

    void devices()
    {
        /** Pin 0 */
        this->attachDevice(Default);

        /** Pin 1 */
        this->attachDevice(Default);

        /** Pin 2 */
        this->attachDevice(Default);

        /** Pin 3 */
        this->attachDevice(Default);

        /** Pin 4 */
        this->attachDevice(Default);

        /** Pin 5 */
        this->attachDevice(Default);

        /** Pin 6 */
        this->attachDevice(Default);

        /** Pin 7 */
        this->attachDevice(Default);

        /** Pin 8 */
        this->attachDevice(Default);

        /** Pin 9 */
        this->attachDevice(Default);

        /** Pin 10 */
        this->attachDevice(Default);

        /** Pin 11 */
        this->attachDevice(Default);

        /** Pin 12 */
        this->attachDevice(Default);

        /** Pin 13 */
        this->attachDevice(new Led(D9, NULL));
    }

    void sensors(){}
};

}}