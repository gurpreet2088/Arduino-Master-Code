#include<AFMotor.h>
AF_DCMotor motor1(1);

void setup() {
  // put your setup code here, to run once:
motor1.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:
motor1.run(FORWARD);
}
