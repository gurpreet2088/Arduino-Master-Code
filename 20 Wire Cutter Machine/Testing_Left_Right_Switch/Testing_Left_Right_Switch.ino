
#define leftButton 2
#define rightButton 3

void setup() {
  Serial.begin(9600);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
   
}
 
void loop() {
  Serial.print(digitalRead(rightButton));
  Serial.println();
  Serial.print(digitalRead(leftButton));
  Serial.println();
  delay(1000);
}
 
