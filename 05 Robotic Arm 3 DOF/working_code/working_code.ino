#include <Servo.h>

Servo servo1; //Servos
Servo servo2;
Servo servo3;

const int button1 = 12; //Buttons
const int button2 = 13;

int button1Presses = 0; //Button values
boolean button2Pressed = false;

const int pot1 = A0; //Potentimeters
const int pot2 = A1; 
const int pot3 = A2;

int pot1Val; //Potentimeter values
int pot2Val;
int pot3Val;
int pot1Angle;
int pot2Angle;
int pot3Angle;

int servo1PosSaves[] = {1,1,1,1,1}; //position saves
int servo2PosSaves[] = {1,1,1,1,1};
int servo3PosSaves[] = {1,1,1,1,1};

void setup() {
  servo1.attach(6); // Set up everything and will run once; attach servos and define the pin modes
  servo2.attach(5);
  servo3.attach(3);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  pot1Val = analogRead(pot1); // This will read the values from the potentimeters and store it...
  pot1Angle = map(pot1Val, 0, 1023, 0, 179); // ... and this will map the values from the potentiometers to values the servos can use and store it for later use
  pot2Val = analogRead(pot2); 
  pot2Angle = map(pot2Val, 0, 1023, 0, 179);
  pot3Val = analogRead(pot3);
  pot3Angle = map(pot3Val, 0, 1023, 0, 179);
  

if(digitalRead(button1) == LOW){ // This will check how many times button1 is pressed and save the positions to an array depending on how many times it is pressed; switch/case works like a if statement
    button1Presses++;
    switch(button1Presses){
      case 1:
        servo1PosSaves[0] = pot1Angle;
        servo2PosSaves[0] = pot2Angle;
        servo3PosSaves[0] = pot3Angle;
        Serial.println("Pos 1 Saved");
        delay(2000);
        break;
      case 2:
         servo1PosSaves[1] = pot1Angle;
         servo2PosSaves[1] = pot2Angle;
         servo3PosSaves[1] = pot3Angle;
         Serial.println("Pos 2 Saved");
         break;
      case 3:
         servo1PosSaves[2] = pot1Angle;
         servo2PosSaves[2] = pot2Angle;
         servo3PosSaves[2] = pot3Angle;
         Serial.println("Pos 3 Saved");
         break;
       case 4:
         servo1PosSaves[3] = pot1Angle;
         servo2PosSaves[3] = pot2Angle;
         servo3PosSaves[3] = pot3Angle;
         Serial.println("Pos 4 Saved");
         break;
       case 5:
         servo1PosSaves[4] = pot1Angle;
         servo2PosSaves[4] = pot2Angle;
         servo3PosSaves[4] = pot3Angle;
         Serial.println("Pos 5 Saved");
         break;
    }
  }

  if(digitalRead(button2) == LOW){ // Pretty self-explnatory here
    button2Pressed = true;   
  }
  
  {if(button2Pressed){ // if the boolean button2Press is true, then the servos will run though all their saved positions
    for(int i = 0; i < 5; i++){
        servo1.write(servo1PosSaves[i]);
        servo2.write(servo2PosSaves[i]);
        servo3.write(servo3PosSaves[i]);
        Serial.println(" potentimeter Angles: ");
        Serial.println(servo1PosSaves[i]);
        Serial.println(servo2PosSaves[i]);
        Serial.println(servo3PosSaves[i]);
        Serial.println(i);
        delay(5050);
      }
      button2Pressed = false;
  }
      else
      {
          servo1.write(pot1Angle); // These will make the servos move to the mapped angles
  servo2.write(pot2Angle);
  servo3.write(pot3Angle);
  Serial.println(pot1Angle);
  Serial.println(digitalRead(button1));
      }
      
  }
  delay(300);
} 
