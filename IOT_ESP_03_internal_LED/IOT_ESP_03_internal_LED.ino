//#define BUILTIN_LED 16 // for NodeMCU v0.9 it seems to be internally defined at 16
#define BUILTIN_LED 2 // for LoLin NodeMCU v3 ESP 12E


void setup() {
   Serial.begin(115200);
   pinMode(BUILTIN_LED, OUTPUT);  
}

void loop() {
  Serial.println("Blink ");

  digitalWrite(BUILTIN_LED, LOW);                                      
  delay(500);                      
 
  digitalWrite(BUILTIN_LED, HIGH);   
  delay(500);   
}
