#include <ZumoMotors.h>
#include <Pushbutton.h>

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);
void setup() {
  
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
 
  advance();
  delay(1000);
  reverse();
}

void advance(){
  motors.setSpeeds(80,80);
  delay(500);
  motors.setSpeeds(0,0);
}

void reverse(){
  motors.setSpeeds(-80,-80);
  delay(500);
  motors.setSpeeds(0,0);
}
