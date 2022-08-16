/*     Arduini PIR Motion Sensor Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
int pirSensor = 8;
int led = 5;
void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Program is started!");
}
void loop() {
  int sensorValue = digitalRead(pirSensor);
  if (sensorValue == 1) {
    Serial.print(sensorValue);
    digitalWrite(led,HIGH);
  }
  else{
  Serial.println("No output is detected");
  digitalWrite(led,LOW);}
}
