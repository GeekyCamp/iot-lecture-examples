#define LED 5
//#define BUTTON 0
#define BUTTON 4

int buttonState = 0;

void setup() {
   pinMode(LED, OUTPUT);
   pinMode(BUTTON, INPUT_PULLUP);
   Serial.begin(115200);
}

void loop() {

  buttonState = digitalRead(BUTTON);
  if (buttonState == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    Serial.println("pressed");
    digitalWrite(LED, LOW);
  }
}

// TODO debounce

// https://github.com/esp8266/Arduino/issues/123
// GPIO 16 is multiplexed with the builtin LED
