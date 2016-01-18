#include "ESP8266WiFi.h"

void setup() {
  
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA); //station mode
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {

  Serial.println("Scanning for WiFi networks....");

  int n = WiFi.scanNetworks();
  Serial.println("Scan complete.");
  
  if (n == 0){
    Serial.println("No networks found");
  } else  {
    Serial.print(n);
    Serial.println("Found networks:");
    for (int i = 0; i < n; ++i){
      
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i)); //the strength of the received signal (0 to -100)
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("Will scan again after 15 seconds");
  delay(15000);
}
