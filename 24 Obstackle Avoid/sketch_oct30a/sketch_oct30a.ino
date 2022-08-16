
#include <Servo.h>
Servo myservo;
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#include <NewPing.h>
NewPing sonar(A0, A1, 200);

void setup() {

  Serial.begin(9600);
  Serial.print("System is started..............");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  analogWrite(5, 75);
  analogWrite(6, 75);

  myservo.attach(13);
  myservo.write(90);

  pinMode(A0, OUTPUT); //trig pin here
  pinMode(A1, INPUT); //echo pin here
}

void loop()
{
  int distanceL = 0;
  int distanceR = 0;

  int distance = readcm();
  Serial.print(distance);
  Serial.println("cm");
//  delay(1000);
  if (distance <= 35)
  {
    stop();
    delay(1000);

    distanceL = lookLeft();
    Serial.println("My left value is");
    Serial.print(distanceL);
    delay(1000);
    distanceR = lookRight();
    Serial.println("My Right value is");
    Serial.print(distanceR);
    delay(1000);
    if (distanceL >= distanceR)
    {
      left();
      delay(400);
      stop();
    }
    else
    {
      right();
      delay(400);
      stop();
    }
  }
  else
  {
    forward();
  }


}

int lookLeft()
{
  myservo.write(140);
  delay(500);
  int cm = readcm();
  delay(800);
  myservo.write(90);
  return cm;
  delay(800);
}
int lookRight()
{
  myservo.write(40);
  delay(500);
  int cm = readcm();
  delay(800);
  myservo.write(90);
  return cm;
  delay(800);
}
int readcm() {
  //  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = 190;
  }
  return cm;
}
void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}

void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}