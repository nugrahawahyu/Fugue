#ifndef Nugraha_TugasAkhirWahyu_Foundation_BaseController
#define Nugraha_TugasAkhirWahyu_Foundation_BaseController

namespace Nugraha { namespace TugasAkhirWahyu { namespace Foundation {

class BaseController {
public:
    virtual void setup();
    virtual void loop();
};

}}}
#endif