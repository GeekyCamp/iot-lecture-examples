//#define BUILTIN_LED 16
#define LED 5

void setup() {
   pinMode(LED, OUTPUT);
   pinMode(BUILTIN_LED, OUTPUT);  
   Serial.begin(115200);
}

void loop() {
  Serial.println("Blink");
  digitalWrite(LED, LOW);
  digitalWrite(BUILTIN_LED, HIGH);                                      
  delay(500);                      
  
  digitalWrite(LED, HIGH);
  digitalWrite(BUILTIN_LED, LOW);   
  delay(500); 
}
