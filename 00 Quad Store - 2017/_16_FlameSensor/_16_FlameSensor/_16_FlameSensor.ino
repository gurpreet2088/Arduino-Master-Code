/*********************************************************** 
File name:   16_flamesensor.ino 
Description:  Flame Sensor. 
Website: www.quadstore.in ***********************************************************/ 

int flameSensorPin = 0; // the cell and 10K pulldown are connected to a0 
int flameSensorReading; // the analog reading from the analog resistor divider 
 
void setup(void) 
{  Serial.begin(9600);  } 
 
void loop(void) { 
 
flameSensorReading = analogRead(flameSensorPin);  
 
Serial.print("Analog reading = "); 
Serial.println(flameSensorReading); // the raw analog reading delay(1000); 
 
}
