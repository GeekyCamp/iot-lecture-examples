
void setup() {
  Serial.begin(115200);
}

void loop() {

  delay(1000); // shall be used for delays [2ms: 10s of ms]. Interrupts still work
  delayMicroseconds(100); // Use for delays of [3us :2ms]. As of Arduino 0018 no longer disables interrupts.
  Serial.println("I am alive");
}

// https://www.arduino.cc/en/Reference/DelayMicroseconds
// http://forum.arduino.cc/index.php?topic=46452.0
