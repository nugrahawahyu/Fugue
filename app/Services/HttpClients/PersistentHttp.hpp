namespace App { namespace Services { namespace HttpClients {
using Nugraha::Services::Esp8266::WifiHttpClient;

class PersistentHttp : public virtual WifiHttpClient
{
public:
    PersistentHttp(std::map<String, String> setting) : WifiHttpClient(setting) {}

    void service()
    {
        Debug::println(F("Memulai service koneksi HTTP Persistent..."));

        interval = 0;
        http.setReuse(true);

        Scheduler::every(interval, [=]() {
            updateMessage();
            httpGet(generateUri(), [=]() {
                board->executeUserCommand(response);
            });
        });
    }
};

}}}