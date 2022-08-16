#include<SoftwareSerial.h>

#define TxD 8
#define RxD 9

#define IN1 10
#define IN2 11
#define IN3 12
#define IN4 13

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;

int counter = 0;

void setup()

{
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("system started");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop()
{
    if(bluetoothSerial.available()){
      c = bluetoothSerial.read();
      Serial.println(c);
      if(c=='F'){
        forward();
        Serial.println("Moving Forward");
        Serial.print(c);
        counter = 0;
  
      }
      if(c=='B'){
        reverse();
        Serial.println("Taking Reverse");
        Serial.print(c);
        counter = 1;
  
      }
      if(c=='L' && counter == 0){
         left();
        Serial.println("Forward Left");
        Serial.print(c);
  
      }
      if(c=='R' && counter == 0){
        right();
        Serial.println("Forward Right");
        Serial.print(c);
  
      }
      if(c=='L' && counter == 1){
         Bleft();
        Serial.println("Backward Left");
        Serial.print(c);
  
      }
      if(c=='R' && counter == 1){
        Bright();
        Serial.println("Backward Right");
        Serial.print(c);
  
      }
       if(c=='G'){
        leftFull();
        Serial.println("Taking Full left turn");
        Serial.print(c);
  
      }
      if(c=='I'){
        rightFull();
        Serial.println("Taking Full Right turn");
        Serial.print(c);
  
      }
      if(c=='S'){
        stop();
        Serial.println("Stopping !!!!");
        Serial.print(c);
  
      }
    }
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void leftFull()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Bleft()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void rightFull()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void Bright()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
