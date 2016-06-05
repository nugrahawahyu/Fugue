namespace Nugraha { namespace Support { namespace Facades {

class Route
{
public:
    static ESP8266WebServer* server;

    template<typename Controller>
    static void get(const char* uri, Controller controller)
    {

    }
};

ESP8266WebServer* Route::server =  env::server::server;

}}}