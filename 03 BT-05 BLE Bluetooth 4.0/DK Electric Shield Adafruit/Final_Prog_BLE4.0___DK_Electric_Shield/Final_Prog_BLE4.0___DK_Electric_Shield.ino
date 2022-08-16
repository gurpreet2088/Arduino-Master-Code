char data = 0;

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
  motor3.setSpeed(150);
  motor3.run(RELEASE);
  motor4.setSpeed(150);
  motor4.run(RELEASE);
}

void loop() {
   if(Serial.available() > 0)  
   {
      data = Serial.read(); 
      Serial.println(data);
                
      if(data == 'a')
      {
        Serial.println("i got signal a");
        forward();
      }
      else if(data =='c')
      {
        Serial.println("i got signal c");
        back(); 
      }
      else if(data =='d')
      {
        Serial.println("i got signal d");  
        left(); 
      }
      else if(data =='b')
      {
        Serial.println("i got signal b"); 
        right(); 
      }
      else
      {
        stop();
      }
      
      
   }
 }

 void forward()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
 void back()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void stop()
{
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 
}
void left()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void right()
{


  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
