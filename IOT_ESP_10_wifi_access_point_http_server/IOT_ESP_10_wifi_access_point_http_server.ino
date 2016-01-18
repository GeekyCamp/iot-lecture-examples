#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "ESP8266";
//const char *password = "iamalive";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>ESP8266 web server works</h1>");
}

void returnTemperature(){
  float temperature = 25.87; 
  server.send(200, "application/json", "{\"temperature\":" + String(temperature) + "}");
}

void setup() {
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.softAP(ssid);
  //WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", handleRoot);
  server.on("/temperature", returnTemperature);
  server.begin();
  
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}