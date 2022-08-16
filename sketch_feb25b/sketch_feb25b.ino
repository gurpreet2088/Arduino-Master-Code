int pin1 = 10;
int pin2 = 11;

unsigned long duration1;
unsigned long duration2;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
}

void loop() {
  duration1 = pulseIn(pin1, HIGH);
  duration2 = pulseIn(pin2, HIGH);
  Serial.print("Ch 1 = ");
  Serial.print(duration1);
  Serial.print("\t");
  Serial.print("Ch 2 = ");
  Serial.println(duration2);
  Serial.println();
  
}
