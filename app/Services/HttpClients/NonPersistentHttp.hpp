namespace App { namespace Services { namespace HttpClients {
using Nugraha::Services::Esp8266::WifiHttpClient;

class NonPersistentHttp : public virtual WifiHttpClient
{
public:
    NonPersistentHttp(std::map<String, String> setting) : WifiHttpClient(setting) {}

    void service()
    {
        Debug::println(F("Memulai service koneksi HTTP Non-persistent..."));

        interval = 0;
        http.setReuse(false);

        Scheduler::every(interval, [=]() {
            updateMessage();
            httpGet(generateUri(), [=]() {
                board->executeUserCommand(response);
            });
        });
    }
};

}}}