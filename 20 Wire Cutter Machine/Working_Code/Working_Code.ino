#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // LCD connected to these pins as rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13

#include <Servo.h>
Servo myservo;

const int stepPin = 7; // Stepper Motor as Extruder step pin 7
const int dirPin = 6; // stepper Motor as Extruder Direction pin 6

#define leftButton 2
#define rightButton 3

int cm = 0;

void setup()
{
  lcd.begin(16, 2); // Define columns and rows on LCD
  lcd.print("By: ");// Display Initial Massage on the display
  lcd.setCursor(0, 1);
  lcd.print("Dilpreet BHOGAL");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SELT LENGTH INCH");
  lcd.setCursor(0, 1);
  lcd.print("DEC");
  lcd.setCursor(13, 1);
  lcd.print("INC");
  delay(100);

  myservo.attach(4); // Servo motor for cutting attached to Pin 4
  myservo.write(90); // Write servo with initial open angle for cutter


  pinMode(stepPin, OUTPUT); // Define two pins as Outputs for Stepper
  pinMode(dirPin, OUTPUT);

  Serial.begin(9600);
  Serial.print("System is Started");
  Serial.println();
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);

}
void loop()
{

  if (digitalRead(rightButton)&& !digitalRead(leftButton) == 1)
  {
    if (cm == 8)
    {
      cm = 8;
    }
    else
    {
      cm += 1;
    }
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("CM =");
    lcd.setCursor(0, 1);
    lcd.print("DEC");
    lcd.setCursor(10, 0);
    lcd.print(cm);
    lcd.setCursor(13, 1);
    lcd.print("INC");
  }
  if (digitalRead(leftButton)&& !digitalRead(rightButton) == 1)
  {
    if (cm == 0)
    {
      cm = 0;
    }
    else
    {
      cm -= 1;
    }
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("CM =");
    lcd.setCursor(0, 1);
    lcd.print("DEC");
    lcd.setCursor(10, 0);
    lcd.print(cm);
    lcd.setCursor(13, 1);
    lcd.print("INC");
  }
  Serial.print(cm);
  delay(500);

  if (digitalRead(rightButton)&& digitalRead(leftButton) == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Processing......");

    digitalWrite(dirPin,LOW);
    for(int x = 0; x < cm*160; x++)
    {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    }
    delay(2000);
    myservo.write(20);
    delay(2000);
    myservo.write(90);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cutting Done");
    delay(5000);
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("CM =");
    lcd.setCursor(0, 1);
    lcd.print("DEC");
    lcd.setCursor(10, 0);
    lcd.print(cm);
    lcd.setCursor(13, 1);
    lcd.print("INC");
  }

  //  myservo.write(20);
  //  myservo.write(20);
  //  delay(2000);
  //  myservo.write(90);
  //  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  //  for(int x = 0; x < 200; x++)
  //  {
  //    digitalWrite(stepPin,HIGH);
  //    delayMicroseconds(500);
  //    digitalWrite(stepPin,LOW);
  //    delayMicroseconds(500);
  //  }
  //  delay(1000); // One second delay
}
