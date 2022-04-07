int Buzz = 2;

void setup() {
  pinMode(Buzz, OUTPUT);
}

void loop() {
  tone(Buzz, 200);
  delay(300);
  noTone(Buzz);
  delay(300);

}
