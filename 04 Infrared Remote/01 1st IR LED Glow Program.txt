#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0x9716BE3F
#define BUTTON_2 0x3D9AE3F7
#define BUTTON_3 0x6182021B
#define BUTTON_0 0x1BC0157B
#define BUTTON_OK 0x488F3CBB

int blue_LED = 7;
int red_LED = 6;
int green_LED = 5;


void setup()
{
  pinMode(blue_LED, OUTPUT);
  pinMode(red_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    Serial.print(0x9716BE3F);
    Serial.print("  ");
    Serial.print(results.value);
    Serial.print("  ");
    if (results.value == BUTTON_0)
    {

      
      digitalWrite(blue_LED, LOW);
      digitalWrite(red_LED, LOW);
      digitalWrite(green_LED, LOW);
    }
    if (results.value == BUTTON_OK)
    {
      digitalWrite(blue_LED, HIGH);
      digitalWrite(red_LED, HIGH);
      digitalWrite(green_LED, HIGH);
    }
    if (results.value == BUTTON_1)
    {
      digitalWrite(blue_LED, HIGH);
    }
    if (results.value == BUTTON_2)
    {
      digitalWrite(red_LED, HIGH);
    }
    if (results.value == BUTTON_3)
    {
      digitalWrite(green_LED, HIGH);
    }
    irrecv.resume();
  }
}
