namespace env {

    namespace wifi {
        String ssid = "Fugue2";
        String password = "fugue123";
        IPAddress ip(192, 168, 137, 69);
        IPAddress subnet(255, 255, 255, 0);
        IPAddress gateway(192, 168, 137, 1);
        IPAddress dns1(8, 8, 8, 8);
        IPAddress dns2(8, 8, 4, 4);
    }

    namespace httpClient {
        String host = "www.wahyunugraha.com";
        String mode = "publish";
        String publishKey = "pub-w-3e5de365-5d57-48c7-a317-366ef2846eb4";
        String subscribeKey = "sub-n-cca59b64-d972-11e5-bdd5-02ee2ddab7fe";
        String signature = "0";
        String channelName = "rumah1";
        String callback = "0";
    }

    namespace server {
        ESP8266WebServer* server =  new ESP8266WebServer(80);
    }

}