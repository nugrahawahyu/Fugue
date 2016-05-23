namespace env {

    namespace wifi {
        String ssid = "Fugue2";
        String password = "Fugue2";
    }

    namespace server {
        ESP8266WebServer* server =  new ESP8266WebServer(80);
    }

    namespace httpClient {
        String hostIp = "54.249.82.173";
        String mode = "publish";
        String publishKey = "pub-c-3e5de365-5d57-48c7-a317-366ef2846eb4";
        String subscribeKey = "sub-c-cca59b64-d972-11e5-bdd5-02ee2ddab7fe";       
    }

}