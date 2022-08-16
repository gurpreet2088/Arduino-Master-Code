#include<SoftwareSerial.h>

#define TxD 3
#define RxD 2

#define LDIR 8
#define LSTOP 9
#define LPWM A0

#define RDIR 10
#define RSTOP 11
#define RPWM A1

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;

void setup() {
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LDIR, OUTPUT);
  pinMode(LSTOP, OUTPUT);

  pinMode(LPWM, OUTPUT);
  
  pinMode(RDIR, OUTPUT);
  pinMode(RSTOP, OUTPUT);
  pinMode(RPWM, OUTPUT);

  }

void loop() {

  analogWrite(LPWM,130);
  analogWrite(RPWM,130);

  
  if(bluetoothSerial.available()){
    c = bluetoothSerial.read();
    Serial.println(c);
    if(c=='1'){
      analogWrite(LPWM,130);
      analogWrite(RPWM,130);
      forward();
      Serial.println("Moving Forward");
      Serial.print(c);
             
    }
    if(c=='2'){
      analogWrite(LPWM,130);
      analogWrite(RPWM,130);
      reverse();
      Serial.println("Taking Reverse");
      Serial.print(c);
       
    }
    if(c=='3'){
      analogWrite(LPWM,130);
      analogWrite(RPWM,130);
      left();
      Serial.println("Turning Left");
      Serial.print(c);
       
    }
    if(c=='4'){
      analogWrite(LPWM,130);
      analogWrite(RPWM,130);
      right();
      Serial.println("Turning Right");
      Serial.print(c);
       
    }
    if(c=='6'){
      analogWrite(LPWM,220);
      analogWrite(RPWM,220);
      forward();
      Serial.println("mOVING FWD FULL SPPED AND TORQUE");
      Serial.print(c);
       
    }
    if(c=='7'){
      analogWrite(LPWM,220);
      analogWrite(RPWM,220);
      reverse();
      Serial.println("mOVING BWD FULL SPPED AND TORQUE");
      Serial.print(c);
       
    }
    if(c=='5'){
      stoprobot();
      Serial.println("Stopping !!!!");
      Serial.print(c);
       
    }
  }
}

void forward()
{
  digitalWrite(LDIR, LOW);
  digitalWrite(LSTOP, LOW);
  digitalWrite(RDIR, LOW);
  digitalWrite(RSTOP, LOW);
}

void reverse()
{
  digitalWrite(LDIR, HIGH);
  digitalWrite(LSTOP, LOW);
  digitalWrite(RDIR, HIGH);
  digitalWrite(RSTOP, LOW); 
}

void left()
{
  digitalWrite(LDIR, HIGH);
  digitalWrite(LSTOP, LOW);
  digitalWrite(RDIR, LOW);
  digitalWrite(RSTOP, LOW); 
}

void right()
{
  digitalWrite(LDIR, LOW);
  digitalWrite(LSTOP, LOW);
  digitalWrite(RDIR, HIGH);
  digitalWrite(RSTOP, LOW);
}

void stoprobot()
{
  digitalWrite(LDIR, LOW);
  digitalWrite(LSTOP, HIGH);
  digitalWrite(RDIR, LOW);
  digitalWrite(RSTOP, HIGH);
}
