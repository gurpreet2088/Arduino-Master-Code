#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 6

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);                               
  Serial.println("System is started.....");

}
void loop() 
{
  analogWrite(IN1, 150);//Left Motor
  analogWrite(IN2, 0);
  analogWrite(IN3, 150); // Right Motor
  analogWrite(IN4, 0); 
  delay(5000);
  analogWrite(IN1, 0);//Left Motor
  analogWrite(IN2, 0);
  analogWrite(IN3, 0); // Right Motor
  analogWrite(IN4, 0);
  delay(5000);
  analogWrite(IN1, 250);//Left Motor
  analogWrite(IN2, 0);
  analogWrite(IN3, 250); // Right Motor
  analogWrite(IN4, 0); 
  delay(5000);
  analogWrite(IN1, 0);//Left Motor
  analogWrite(IN2, 0);
  analogWrite(IN3, 0); // Right Motor
  analogWrite(IN4, 0);
  delay(5000);
}
