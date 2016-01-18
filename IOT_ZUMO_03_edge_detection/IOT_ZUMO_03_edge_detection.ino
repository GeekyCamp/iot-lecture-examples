#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

#define NUM_SENSORS 6

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

ZumoReflectanceSensorArray reflectanceSensors;
unsigned int sensorValues[NUM_SENSORS];

void setup() {
  
  reflectanceSensors.init();
  
  Serial.begin(115200);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  unsigned int batteryVoltageMV = analogRead(1) * 5000L * 3/2 / 1023;
  Serial.print("Battery voltage [mV]: ");
  Serial.println(batteryVoltageMV);

  if(batteryVoltageMV < 4800){
    Serial.println("Battery is low!");
  }

  Serial.println("Press the button to calibrate and move the robot across the edge.");
  button.waitForButton();
  calibrate();

  Serial.println("Calibration done. Press the button to continue.");
  button.waitForButton();
}

void calibrate(){
  int i;
  
  for (i = 0; i < 250; i++){
    reflectanceSensors.calibrate();
    delay(20);
  } 
}

void loop() {
  
  int count = readReflectanceArray();
  if(count > 3){
    motors.setSpeeds(-70,-100);
    delay(700);
  }
  motors.setSpeeds(70,70);
  delay(300);
}

int readReflectanceArray(){

   //reflectanceSensors.readLine(sensorValues); // for line following
   reflectanceSensors.readCalibrated(sensorValues);
//   reflectanceSensors.read(sensorValues);
   Serial.print("Reflectance sensor raw values: ");
   int count = 0;
   int i;
   for (i = 0; i < NUM_SENSORS; i++) {
      Serial.print(sensorValues[i]);
      Serial.print(", ");
      if(sensorValues[i] > 650){
        count++;
      }
    }
   Serial.println("");
   return count;
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

void stop(){
   motors.setSpeeds(0,0);
}
