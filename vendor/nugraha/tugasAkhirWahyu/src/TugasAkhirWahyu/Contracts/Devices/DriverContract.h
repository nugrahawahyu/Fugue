#ifndef Nugraha_TugasAkhirWahyu_Contract_Device_DriverContract
#define Nugraha_TugasAkhirWahyu_Contract_Device_DriverContract


namespace Nugraha { namespace TugasAkhirWahyu { namespace Contracts { namespace Devices {

    class DriverContract {
    public:
        virtual bool turnOn(int pin)=0;
        virtual bool turnOff(int pin)=0;
    };
}}}}

#endif