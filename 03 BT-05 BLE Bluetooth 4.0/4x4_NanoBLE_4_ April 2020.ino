char data = 0;

#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);                               
  Serial.println("System is started.....");

}

void loop() 
{
  if(Serial.available() > 0)  
   {
      data = Serial.read(); 
      Serial.println(data);
                
      if(data == 'a' || data =='e')
      {
        forward();
      }
      else if(data =='c' || data =='g')
      {
         
        back(); 
      }
      
      else if(data =='h')
      {
        
        left(); 
      }
      else if(data =='f')
      {
        
        right(); 
      }
      else if(data =='d')
      {
        
        halfleft(); 
      }
      else if(data =='b')
      {
        
        halfright(); 
      }
      else
      {
        stop();
         
      }
   }
  
//  forward();
//  delay(1000);
//  stop();
//  delay(1000);
  
}

void forward()
{
  digitalWrite(IN1, HIGH);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // LEFT MOTOR
  digitalWrite(IN4, LOW); 
}
void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW); 
}
void back()
{
  digitalWrite(IN1, LOW);//RIGHT MOTOR
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); // LEFT MOTOR
  digitalWrite(IN4, HIGH); 
}
void left()
{
   digitalWrite(IN1, LOW);//RIGHT MOTOR
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); // LEFT MOTOR
  digitalWrite(IN4, LOW);
}
void right()
{
 
    digitalWrite(IN1, HIGH);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // LEFT MOTOR
  digitalWrite(IN4, HIGH);
}
void halfleft()
{
   digitalWrite(IN1, LOW);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // LEFT MOTOR
  digitalWrite(IN4, LOW);
}
void halfright()
{
 
    digitalWrite(IN1, HIGH);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // LEFT MOTOR
  digitalWrite(IN4, LOW);
}
