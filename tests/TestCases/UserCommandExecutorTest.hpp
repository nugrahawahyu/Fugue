namespace Tests { namespace TestCases { 
using Nugraha::Foundation::Application;
using Nugraha::Foundation::BaseController;

class UserCommandExecutorTest : public virtual BaseController
{
public:
    void setup(void) 
    {
        board->executeUserCommand("{\"commands\":[{\"id\":12,\"pin\":14,\"action\":\"turnOn\",\"sent\":true,\"created_at\":\"2016-05-24 17:29:18\",\"updated_at\":\"2016-05-24 17:29:35\",\"sent_at\":{\"date\":\"2016-05-24 17:29:35.000000\",\"timezone_type\":3,\"timezone\":\"Asia\/Jakarta\"}},{\"id\":13,\"pin\":2,\"action\":\"turnOn\",\"sent\":true,\"created_at\":\"2016-05-24 17:29:31\",\"updated_at\":\"2016-05-24 17:29:35\",\"sent_at\":{\"date\":\"2016-05-24 17:29:35.000000\",\"timezone_type\":3,\"timezone\":\"Asia\/Jakarta\"}}]}");
    }

    void loop() 
    {

    }
};

}}