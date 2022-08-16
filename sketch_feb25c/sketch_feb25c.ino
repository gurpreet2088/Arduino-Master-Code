#define IN1 10
#define IN2 11
#define IN3 6
#define IN4 9
void setup() {
  Serial.begin(9600);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  
  analogWrite(IN1, 0);//RIGHT MOTOR
  analogWrite(IN2, 0);
  analogWrite(IN3, 0); // LEFT MOTOR
  analogWrite(IN4, 0);
  delay(2000);

}
