/*********************************************************** 
File name:   15_lm35temp.ino 
Description:  Lit LED, let LED blinks. 
Website: www.quadstore.in ***********************************************************/ 

int val;
int tempPin = A0; 
 
void setup() 
{ 
  Serial.begin(9600); 
} 
void loop()
{ 
  val = analogRead(tempPin); 
  float mv = ( val/1024.0)*5000;  

 
 
float cel = mv/10; float farh = (cel*9)/5 + 32; 
 
Serial.print("TEMPRATURE = "); Serial.print(cel); Serial.print("*C"); Serial.println(); delay(1000); 
 
/* uncomment this to get temperature in farenhite  Serial.print("TEMPRATURE = "); Serial.print(farh); Serial.print("*F"); Serial.println(); 
 
 
*/ } 
