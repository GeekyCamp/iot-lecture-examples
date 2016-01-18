#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;

void setup() {
    Serial.begin(115200);
    delay(10);

    // Connect to a network. This API supports multiple access points (AP).
    WiFiMulti.addAP("my network", "my network password"); // password is optional
    Serial.println();
    
    Serial.print("Wait for WiFi to connect ... ");
    while(WiFiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("");
    Serial.println("WiFi connected");
    
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Netmask: ");
    Serial.println(WiFi.subnetMask());

    Serial.println("Gateway: ");
    Serial.println(WiFi.gatewayIP());

    Serial.println("MAC address: ");
    Serial.println(WiFi.macAddress());

    delay(500);
}


void loop() {
    const uint16_t port = 80;
    const char * host = "requestb.in"; // ip or dns
    const char * url = "/123ylwv1";
 
    Serial.print("connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;

    if (!client.connect(host, port)) {
        Serial.println("connection failed");
        Serial.println("wait 5 sec...");
        delay(5000);
        return;
    }

    float temperature = 25.87;
    String postData = "{\"temperature\":" + String(temperature) + "}";
    client.print(String("POST ") + url + " HTTP/1.1\r\n" + 
                "Host: " + host + "\r\n" +
                "User-Agent: ESP8266\r\n" +
                "Connection: close\r\n" +
                "Content-Type: application/json\r\n" +
                "Content-Length: " + postData.length() + "\r\n\r\n" +
                postData + "\r\n"
                );
    
    Serial.println("request sent");
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("headers received");
        break;
      }
    }
    
    String line = client.readStringUntil('\n');
    if (line.startsWith("{\"state\":\"success\"")) {
      Serial.println("esp8266/Arduino CI successfull!");
    } else {
      Serial.println("esp8266/Arduino CI has failed");
    }
    Serial.println("reply was:");
    Serial.println("==========");
    Serial.println(line);
    Serial.println("==========");
    
    Serial.println("closing connection");
    client.stop();
    
    delay(10000);
}


