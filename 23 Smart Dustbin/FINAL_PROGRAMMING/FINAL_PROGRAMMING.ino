#define trigPin 8
#define echoPin 9

#include <VarSpeedServo.h> 
VarSpeedServo servo1;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(7);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 15) {  //you are free to change this
    Serial.println(" BELOW 15 CM"); //in centimeters
    servo1.write(40,20);
    servo1.wait();
    servo1.write(113,20);
    servo1.wait();
    delay(15000);
    servo1.write(40,20);
    servo1.wait();
    
  }
  else {

    Serial.println(" ABOVE 15CM BUT IN RANGE"); //in centimeters
  }
  if (distance >= 100 || distance <= 0) {   //range is 400 cm for HC-SR04 sensor
    Serial.println("OUT OF RANGE");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm"); //in centimeters
  }
  delay(200);
}
