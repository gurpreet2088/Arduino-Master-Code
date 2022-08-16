#include <AFMotor.h>

AF_DCMotor motor1(1); AF_DCMotor motor4(4);
AF_DCMotor motor2(2); AF_DCMotor motor3(3);

#include <Servo.h>

Servo myservo;
Servo myservo1;

void setup() 
{
  Serial.begin(9600);                               
  Serial.println("System is started.....");

  motor1.setSpeed(150);
  motor1.run(RELEASE);
  motor2.setSpeed(150);
  motor2.run(RELEASE);
  motor3.setSpeed(150);
  motor3.run(RELEASE);
  motor4.setSpeed(150);
  motor4.run(RELEASE);

  myservo.attach(10);
  myservo1.attach(9);

}

void loop() {

  myservo.write(0);
  myservo1.write(0);
  delay(4000);
  myservo.write(90);
  myservo1.write(90);
  delay(4000);
  myservo.write(180);
  myservo1.write(180);
  delay(4000);
//  myservo.write(180);
//  delay(4000);
//  myservo.write(90);
//  delay(4000); 
//  myservo.write(0);
//  delay(4000);  
 }

 void forward()
{
    motor1.run(FORWARD); motor4.run(FORWARD);
    motor2.run(FORWARD); motor3.run(FORWARD);
}
 void back()
{
    motor1.run(BACKWARD); motor4.run(BACKWARD);
    motor2.run(BACKWARD); motor3.run(BACKWARD);
  
}
void stop()
{
    motor1.run(RELEASE); motor4.run(RELEASE);
    motor2.run(RELEASE); motor3.run(RELEASE);
}
void left()
{
    motor1.run(BACKWARD); motor4.run(FORWARD);
    motor2.run(BACKWARD); motor3.run(FORWARD);
}
void right()
{
    motor1.run(FORWARD); motor4.run(BACKWARD);
    motor2.run(FORWARD); motor3.run(BACKWARD);
}

 
