#include <Keypad.h>

#define Password_Length 5 //define length of pass
char Data[Password_Length]; 
char Master[Password_Length] = "123A"; //define master pass
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {4, 5, 6, 7}; //define pins first 4 left
byte colPins[COLS] = {8, 9, 10, 11}; //define next 4 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
 
void setup(){
  Serial.begin(9600);
  Serial.print("Please Enter Pass \n");
  Serial.print("Pass: ");
}

void loop(){

  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    Serial.print("*");
    data_count++; 
    }

  if(data_count == Password_Length-1){

    if(!strcmp(Data, Master)){
      Serial.print("\nAccess Granted");
      Serial.print("\nWelcome to ICE Robotics");
      //digitalWrite(signalPin, HIGH); 
      delay(5000);
      //digitalWrite(signalPin, LOW);
      }
    else{
      Serial.print("\nIncorrect");
      Serial.print("\nAccess Denied");
      Serial.print("\nContact Front Desk");
      delay(5000);
      }
    
    //lcd.clear();
    clearData();  
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  Serial.println("\nPlease enter password");
  return;
}
