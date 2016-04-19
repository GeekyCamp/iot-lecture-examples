#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#define LED 5
#define SENSOR 4


OneWire oneWire(SENSOR);
DallasTemperature sensors(&oneWire);

const char *ssid = "ESP8266";
//const char *password = "iamalive";
int count = 0;
float temperature = 0;

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>ESP8266 web server works" + String(count) + "</h1>");
}

void returnTemperature(){
  server.send(200, "application/json", "{\"temperature\":" + String(temperature) + "}");
}

void setup() {

  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  sensors.begin();
  
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

void readSensors(){
  
 sensors.requestTemperatures();
 temperature = sensors.getTempCByIndex(0);
 Serial.println("Temperature for Device 1 is: " + String(temperature));
}

void loop() {
  server.handleClient(); // seems non-blocking
  
  // we can do other stuff here
  readSensors();
}

//https://www.arduino.cc/en/Tutorial/StringAdditionOperator
