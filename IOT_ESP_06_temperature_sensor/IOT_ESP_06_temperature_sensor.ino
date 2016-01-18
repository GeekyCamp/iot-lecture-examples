#include <OneWire.h>
#include <DallasTemperature.h>

#define LED 5
#define SENSOR 4

OneWire oneWire(SENSOR);
DallasTemperature sensors(&oneWire);


void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  sensors.begin();
}

void loop() {

  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  Serial.print("Temperature for Device 1 is: ");
  Serial.println(temp);
  adjustLED(temp); 
  delay(1000); 
}

// http://www.hobbytronics.co.uk/ds18b20-arduino
// http://erelement.com/sensors/DS18B20-cable
// RED=VCC, BLACK=GND, YELLOW/WHITE=DATA
// 4k7 ohm is needed between VCC and DATA

void adjustLED(float temp){
  if(temp > 45){
    digitalWrite(LED, HIGH);  
  }else {
    digitalWrite(LED, LOW); 
  }
}

