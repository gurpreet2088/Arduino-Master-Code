#include <AFMotor.h>
#include<SoftwareSerial.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#include <VarSpeedServo.h> 
VarSpeedServo servo1;
VarSpeedServo servo2;


#define TxD 13
#define RxD 2

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;

void setup()
{
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("System is started.....");

  motor2.setSpeed(150);
  motor2.run(RELEASE);
  motor3.setSpeed(150);
  motor3.run(RELEASE);

    servo1.attach(10);
    servo2.attach(9);
    
    servo1.write(0,20);
    servo1.wait();
    delay(2000);
    servo2.write(70,10);
    servo2.wait();
    delay(2000);
}

void loop()
{
  if (bluetoothSerial.available()) 
  {
    c = bluetoothSerial.read();
    Serial.println(c);
    if (c == 'F') 
    {
      forward();
      Serial.println("Moving Forward");
      Serial.print(c);

    }
    if (c == 'B') 
    {
      back();
      Serial.println("Taking Reverse");
      Serial.print(c);

    }
    if (c == 'L') 
    {
      left();
      Serial.println("Turning Left");
      Serial.print(c);

    }
    if (c == 'R') 
    {
      right();
      Serial.println("Turning Right");
      Serial.print(c);

    }
    if (c == 'W') 
    {
      Serial.println("I am going to pick object");
      pick();
      Serial.print(c);

    }
    if (c == 'w') 
    {
      Serial.println("Warning!!! I am going to drop object");
      drop();
      Serial.print(c);

    }
    if (c == 'S') 
    {
      stop();
      Serial.println("Stopping !!!!");
      Serial.print(c);

    }
  }

}
void pick()
{
    servo1.write(0,20);
    servo1.wait();
    delay(1000);
    servo2.write(30,10);
    servo2.wait();
    delay(1000);
    servo1.write(102,20);
    servo1.wait();
    delay(1000);
    servo2.write(70,10);
    servo2.wait();
    delay(1000);
    servo1.write(0,20);
    servo1.wait();
    delay(1000);
}
void drop()
{
    servo1.write(102,20);
    servo1.wait();
    delay(1000);
    servo2.write(30,10);
    servo2.wait();
    delay(1000);
    servo1.write(0,20);
    servo1.wait();
    delay(1000);
}
void forward()
{
  motor2.run(FORWARD);
  motor3.run(FORWARD);
}
void back()
{
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
}
void stop()
{
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
void left()
{
  motor2.run(FORWARD);
  motor3.run(RELEASE);
}
void right()
{

  motor2.run(RELEASE);
  motor3.run(FORWARD);

}
