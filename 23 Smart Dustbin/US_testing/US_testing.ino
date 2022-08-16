#define trigPin 13
#define echoPin 12

#include <Servo.h>
Servo myservo;
int pos = 0;
void setup() {
  Serial.begin (9600);
  myservo.attach(8);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 20) {  //you are free to change this
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
 
  if (distance > 100){    //range is 400 cm for HC-SR04 sensor
    Serial.println("Beyond Range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm"); //in centimeters
  }
  
}
