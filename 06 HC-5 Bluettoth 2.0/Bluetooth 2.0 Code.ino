#include<SoftwareSerial.h>

#define TxD 2
#define RxD 3

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;

void setup()

{
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
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
  
      }
      if(c=='B'){
        reverse();
        Serial.println("Taking Reverse");
        Serial.print(c);
  
      }
      if(c=='L'){
         left();
        Serial.println("Turning Left");
        Serial.print(c);
  
      }
      if(c=='R'){
        right();
        Serial.println("Turning Right");
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

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
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
