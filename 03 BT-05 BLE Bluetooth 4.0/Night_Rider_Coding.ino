int enA = A0;
int enB = A1;
#include<SoftwareSerial.h>
char data = 0;
//#define TxD 7
//#define RxD 6

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

//SoftwareSerial bluetoothSerial(TxD, RxD);
char c;

void setup() {
  
  
  Serial.begin(9600);
  Serial.println("System is started.....");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);
  
  analogWrite(enA, 200);
  analogWrite(enB, 200);

//  bluetoothSerial.begin(9600);
//  Serial.begin(9600);

}

void loop() {

   if(Serial.available() > 0)  
   {
      data = Serial.read(); 
      Serial.println(data);
                
      if(data == 'a')
      {
        Serial.println("i got signal a");
        reverse();
      }
      else if(data =='c')
      {
        Serial.println("i got signal c");
        
        forward();
      }
      
      else if(data =='d')
      {
        Serial.println("i got signal d");  
        left(); 
      }
      else if(data =='h')
      {
        Serial.println("i got signal d");  
         leftfull(); 
      }
      else if(data =='f')
      {
        Serial.println("i got signal d");  
        
         rightfull();
      }
        else if(data =='e')
      {
        Serial.println("speed max");  
          analogWrite(enA, 255);
          analogWrite(enB, 255); 
      }
      else if(data =='g')
      {
        Serial.println("speed max");  
          analogWrite(enA, 200);
          analogWrite(enB, 200); 
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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW); 
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH); 
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW); 
}

void leftfull()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH); 
}
void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}
void rightfull()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}

void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
