namespace env {

    namespace wifi {
        String ssid = "Fugue2";
        String password = "fugue123";
        bool obtainIpAddressAutomatically = false;
        IPAddress ip(192, 168, 137, 69);
        IPAddress subnet(255, 255, 255, 0);
        IPAddress gateway(192, 168, 137, 1);
        IPAddress dns1(8, 8, 8, 8);
        IPAddress dns2(8, 8, 4, 4);
    }

    namespace httpClient {
        String host = "www.pubnub.com";
        String mode = "publish";
        String publishKey = "publish-key";
        String subscribeKey = "subscribe-key";
        String signature = "signature";
        String channelName = "channel";
        String callback = "callback";
    }

    namespace server {
        ESP8266WebServer* server =  new ESP8266WebServer(80);
    }

}