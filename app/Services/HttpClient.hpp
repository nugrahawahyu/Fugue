namespace App { namespace Services {
using Nugraha::Services::Esp8266::WifiHttpClient;

class HttpClient : public virtual WifiHttpClient
{
public:
    HttpClient(std::map<String, String> setting, bool isPersistent=true) : WifiHttpClient(setting)
    {
        interval = 0;
        http.setReuse(isPersistent);
    }

    void service()
    {
        Debug::println(F("Memulai service koneksi HTTP Persistent..."));
        Scheduler::every(interval, [=]() {
            updateMessage();
            httpGet(generateUri(), [=]() {
                board->executeUserCommand(response);
            });
        });
    }
};

}}