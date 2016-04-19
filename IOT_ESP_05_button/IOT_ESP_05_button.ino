#define LED 5
#define BUTTON 16

int buttonState = LOW;

void setup() {
   pinMode(LED, OUTPUT);
   pinMode(BUTTON, INPUT_PULLUP); // seems that the internal pullup on LoLin nodemcu v3 doesn't work reliably
   Serial.begin(115200);
}

void loop() {

  buttonState = digitalRead(BUTTON);
 
  if (buttonState == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}









int digitalReadDebounced(int pin){

  int count = 0; 
  int previousState = digitalRead(pin);
  int nextState = previousState;
  const int DESIRED_COUNT = 4; // we require at least 4 readings of the same value
  
  for(int i=0; i<25 && count < DESIRED_COUNT; i++){
    delay(2);
    int nextState = digitalRead(pin);
    if(nextState == previousState){
      count++;
    }
    previousState = nextState;
  }
  if(count >= DESIRED_COUNT){
    Serial.println("Considered stable");
    Serial.println(nextState);
  }else {
    Serial.println("Still bouncing. Maybe EMI");
  }
  return nextState;
}
//http://www.eng.utah.edu/~cs5780/debouncing.pdf

// https://github.com/esp8266/Arduino/issues/123
// GPIO 16 is multiplexed with the builtin LED
