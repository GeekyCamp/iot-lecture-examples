//#define BUILTIN_LED 16

void setup() {
   Serial.begin(115200);
   pinMode(BUILTIN_LED, OUTPUT);  
}

void loop() {
  Serial.println("Blink");
  digitalWrite(BUILTIN_LED, HIGH);                                      
  delay(500);                      
 
  digitalWrite(BUILTIN_LED, LOW);   
  delay(500); 
}
