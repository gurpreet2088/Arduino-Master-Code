#include <Stepper.h>
 
// Define Constants
 
// Number of steps per internal motor revolution 
const float S_P_R = 32; 
 
//  Amount of Gear Reduction
const float G_R = 64;
 
// Number of steps per geared output rotation
const float STEPS_OUT = S_P_R * G_R;
 
// Define Variables
 
// Number of Steps Required
int S_R;
 
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing
 
Stepper Mot1(S_P_R, 8, 10, 9, 11);
 
void setup()
{
// Nothing  (Stepper Library sets pins as outputs)
}
 
void loop()
{
  // Slow - 4-step CW sequence to observe lights on driver board
  Mot1.setSpeed(1);    
  S_R  =  4;
  Mot1.step(S_R);
  delay(2000);
 
   // Rotate CW 1/2 turn slowly
  S_R  =  STEPS_OUT / 2; 
  Mot1.setSpeed(100);   
  Mot1.step(S_R);
  delay(1000);
  
  // Rotate CCW 1/2 turn quickly
  S_R  =  - STEPS_OUT / 2;   
  Mot1.setSpeed(700);  
  Mot1.step(S_R);
  delay(2000);
 
}
