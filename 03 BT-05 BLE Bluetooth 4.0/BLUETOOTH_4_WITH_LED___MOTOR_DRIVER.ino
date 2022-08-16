#define LED 13
char data = 0;


#define IN1 8 
#define IN2 9
#define IN3 10
#define IN4 11

void setup()
{
    pinMode(LED, OUTPUT);
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
                
      if(data == 'a')
      {
        digitalWrite(LED, LOW);
        forward();
      }
      else if(data =='C')
      {
        digitalWrite(LED, LOW); 
        back(); 
      }
      else if(data =='h')
      {
        stop();
        digitalWrite(LED, HIGH); 
      }
      else if(data =='d')
      {
        digitalWrite(LED, LOW); 
        left(); 
      }
      else if(data =='b')
      {
        digitalWrite(LED, LOW); 
        right(); 
      }
      
   }
 }

 void forward()
{
  digitalWrite(IN1, HIGH);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // LEFT MOTOR
  digitalWrite(IN4, LOW); 
}
 void back()
{
  digitalWrite(IN1, LOW);//RIGHT MOTOR
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); // LEFT MOTOR
  digitalWrite(IN4, HIGH); 
}
void stop()
{
  digitalWrite(IN1, LOW);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // LEFT MOTOR
  digitalWrite(IN4, LOW); 
}
void left()
{
  digitalWrite(IN1, HIGH);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // LEFT MOTOR
  digitalWrite(IN4, LOW); 
}
void right()
{
  digitalWrite(IN1, LOW);//RIGHT MOTOR
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // LEFT MOTOR
  digitalWrite(IN4, LOW); 
}