#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup()
{
  Serial.begin(9600);                               
  Serial.println("System is started.....");

  motor1.setSpeed(150);
  motor1.run(RELEASE);
  motor2.setSpeed(150);
  motor2.run(RELEASE);
}

void loop() 
{
   forward();
   delay(2000);
   stop();
   delay(1000);
   back();
   delay(2000);
   stop();
   left();
   delay(5000);
   stop();
   right();
   delay(5000);
   stop();

}
void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);

}
 void back()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);

}
void stop()
{
  motor1.run(RELEASE); 
  motor2.run(RELEASE);

}
void left()
{
  motor1.run(RELEASE);
  motor2.run(FORWARD);

}
void right()
{


  motor1.run(FORWARD);
  motor2.run(RELEASE);

}
