#include<VarSpeedServo.h>

//Servos
VarSpeedServo servo1; // Base Rotation
VarSpeedServo servo2; // Sholder
VarSpeedServo servo3; // Elbow
VarSpeedServo servo4; // Wrist Grip

const int button1 = 12; 
const int button2 = 13;

int LED = 8;

int button1Presses = 0; //Button values
boolean button2Pressed = false;

const int pot1 = A0; //Potentimeters
const int pot2 = A1;
const int pot3 = A2;
const int pot4 = A3;

int pot1Val; //Potentimeter values
int pot2Val;
int pot3Val;
int pot4Val;

int pot1Angle;
int pot2Angle;
int pot3Angle;
int pot4Angle;

int servo1PosSaves[] = {1,1,1,1,1,1,1,1}; //position saves
int servo2PosSaves[] = {1,1,1,1,1,1,1,1};
int servo3PosSaves[] = {1,1,1,1,1,1,1,1};
int servo4PosSaves[] = {1,1,1,1,1,1,1,1};

void setup() {
  servo1.attach(7); // Set up everything and will run once; attach servos and define the pin modes
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  pinMode(LED,OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly: 
  pot1Val = analogRead(pot1); // This will read the values from the potentimeters and store it...
  pot1Angle = map(pot1Val, 0, 1023, 0, 179); // ... and this will map the values from the potentiometers to values the servos can use and store it for later use
  pot2Val = analogRead(pot2); 
  pot2Angle = map(pot2Val, 0, 1023, 0, 179);
  pot3Val = analogRead(pot3);
  pot3Angle = map(pot3Val, 0, 1023, 0, 179);
  pot4Val = analogRead(pot4);
  pot4Angle = map(pot4Val, 1023, 0, 0, 179);
  

if(digitalRead(button1) == LOW){ // This will check how many times button1 is pressed and save the positions to an array depending on how many times it is pressed; switch/case works like a if statement
    button1Presses++;
    switch(button1Presses){
      case 1:
        servo1PosSaves[0] = pot1Angle;
        servo2PosSaves[0] = pot2Angle;
        servo3PosSaves[0] = pot3Angle;
        servo4PosSaves[0] = pot4Angle;
        Serial.println("Pos 1 Saved");
        delay(5000);
        break;
      case 2:
         servo1PosSaves[1] = pot1Angle;
         servo2PosSaves[1] = pot2Angle;
         servo3PosSaves[1] = pot3Angle;
         servo4PosSaves[1] = pot4Angle;
         Serial.println("Pos 2 Saved");
         delay(5000);
         break;
      case 3:
         servo1PosSaves[2] = pot1Angle;
         servo2PosSaves[2] = pot2Angle;
         servo3PosSaves[2] = pot3Angle;
         servo4PosSaves[2] = pot4Angle;
         Serial.println("Pos 3 Saved");
         delay(5000);
         break;
       case 4:
         servo1PosSaves[3] = pot1Angle;
         servo2PosSaves[3] = pot2Angle;
         servo3PosSaves[3] = pot3Angle;
         servo4PosSaves[3] = pot4Angle;
         Serial.println("Pos 4 Saved");
         delay(5000);
         break;
       case 5:
         servo1PosSaves[4] = pot1Angle;
         servo2PosSaves[4] = pot2Angle;
         servo3PosSaves[4] = pot3Angle;
         servo4PosSaves[4] = pot4Angle;
         Serial.println("Pos 5 Saved");
         delay(5000);
         break;
       case 6:
         servo1PosSaves[5] = pot1Angle;
         servo2PosSaves[5] = pot2Angle;
         servo3PosSaves[5] = pot3Angle;
         servo4PosSaves[5] = pot4Angle;
         Serial.println("Pos 6 Saved");
         delay(5000);
         break;
         case 7:
         servo1PosSaves[6] = pot1Angle;
         servo2PosSaves[6] = pot2Angle;
         servo3PosSaves[6] = pot3Angle;
         servo4PosSaves[6] = pot4Angle;
         Serial.println("Pos 7 Saved");
         delay(5000);
         break;
         case 8:
         servo1PosSaves[7] = pot1Angle;
         servo2PosSaves[7] = pot2Angle;
         servo3PosSaves[7] = pot3Angle;
         servo4PosSaves[7] = pot4Angle;
         Serial.println("Pos 8 Saved");
         delay(5000);
         button1Presses = 0;
         break;
    }
  }

  if(digitalRead(button2) == LOW)
  { // Pretty self-explnatory here
    button2Pressed = true;  
    Serial.println(" Starting playback ");
    delay(2000); 
  }
  
  {if(button2Pressed){ // if the boolean button2Press is true, then the servos will run though all their saved positions
    for(int i = 0; i < 6; i++){
        servo1.write(servo1PosSaves[i],30);
        servo1.wait();
        servo2.write(servo2PosSaves[i],15);
        servo2.wait();
        servo3.write(servo3PosSaves[i],25);
        servo3.wait();
        servo4.write(servo4PosSaves[i],25);
        servo4.wait();
        Serial.println(" potentimeter Angles: ");
        Serial.println(servo1PosSaves[i]);
        Serial.println(servo2PosSaves[i]);
        Serial.println(servo3PosSaves[i]);
        Serial.println(i);
        delay(300);
       }   
  }
      else
      {
          servo1.write(pot1Angle,100); // These will make the servos move to the mapped angles
          servo1.wait();
          servo2.write(pot2Angle,100);
          servo2.wait();
          servo3.write(pot3Angle,100);
          servo3.wait();
          servo4.write(pot4Angle,100);
          servo4.wait();

         
  Serial.println("potAngle values");
  Serial.println(pot1Angle);
  Serial.println(pot2Angle);
  Serial.println(pot3Angle);
  Serial.println(pot4Angle);
//  Serial.println("b1 and b2 values");
//  Serial.println(digitalRead(button1));
//  Serial.println(digitalRead(button2));
}
      
  }
  delay(300);
} 
