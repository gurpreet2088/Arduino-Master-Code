
int relay1 = 2;
//int relay2 = 3;

void setup() {
    pinMode(relay1, OUTPUT);// set pin as output for relay 1
   // pinMode(relay2, OUTPUT);// set pin as output for relay 2

    // keep both relay off by keeping both HIGH
    digitalWrite(relay1, HIGH); 
   // digitalWrite(relay2, HIGH); 

    Serial.begin(9600);// initialize serial monitor with 9600 baud
    Serial.println("Control for Relay is ready");
   // Serial.println("Using 2 Relays");  
    delay(2000);

}

void loop() {
  
  digitalWrite(relay1, LOW);// turn relay 1 ON
 // digitalWrite(relay2, HIGH);// turn relay 2 OFF  
  Serial.println("Switched ON relay 1");  
  delay(3000);// wait for 3 seconds

 
  digitalWrite(relay1, HIGH);// turn relay 1 OFF
  //digitalWrite(relay2, HIGH);// turn relay 2 OFF
  Serial.println("Switched OFF relay 1");  
  delay(2000);// stop for 2 seconds

}
