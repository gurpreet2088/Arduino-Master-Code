/*********************************************************** 
File name:   _17_aBuzzer.ino 
Description:  Active Buzzer. 
Website: www.quadstore.in ***********************************************************/ 

int buzzerPin = 9; 
 
void setup () 
{   
  pinMode (buzzerPin, OUTPUT); 
} 
 
void loop ()
{   
digitalWrite (buzzerPin, HIGH);  
delay (500);   
digitalWrite (buzzerPin, LOW);   
delay (500); 
} 
 
 
