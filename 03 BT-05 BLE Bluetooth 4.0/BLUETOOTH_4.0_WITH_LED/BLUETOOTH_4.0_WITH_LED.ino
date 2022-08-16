#define LED 13
char data = 0;

void setup()
{
    pinMode(LED, OUTPUT);
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
        digitalWrite(LED, HIGH);
      }
      else if(data =='b')
      {
        digitalWrite(LED, LOW);
      }
   }
 }
