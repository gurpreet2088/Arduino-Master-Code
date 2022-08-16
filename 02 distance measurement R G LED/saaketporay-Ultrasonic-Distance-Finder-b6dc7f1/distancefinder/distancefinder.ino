#define trigPin 13
#define echoPin 12
#define led 11 //red LED
#define led2 10 //green LED

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
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
  digitalWrite(led,HIGH); //distance is less than 100 so red LED turns on
  digitalWrite(led2,LOW);
}
  else {
  digitalWrite(led,LOW); //distance is more than 100 so green LED turns on
  digitalWrite(led2,HIGH);

  }
  if (distance >= 100 || distance <= 0){    //range is 400 cm for HC-SR04 sensor
    Serial.println("OUT of Range 400");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm"); //in centimeters
  }
  delay(1000);
}
