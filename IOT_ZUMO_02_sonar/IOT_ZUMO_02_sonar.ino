#include <Pushbutton.h>
#include <NewPing.h>

#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 120 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Pushbutton button(ZUMO_BUTTON);

void setup() {
 
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.begin(115200);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  unsigned int batteryVoltageMV = analogRead(1) * 5000L * 3/2 / 1023;
  Serial.print("Battery voltage [mV]: ");
  Serial.println(batteryVoltageMV);

  if(batteryVoltageMV < 4800){
    Serial.print("Battery is low!");
  }
  
  button.waitForButton();
}

void loop() {
  
  float distance =  readSonar();
  
  Serial.print("Distance [cm]: ");
  Serial.println(distance);
  
  delay(700);
}

float readSonar(){
  unsigned int uS = sonar.ping();
  return (float)uS / US_ROUNDTRIP_CM;
}
