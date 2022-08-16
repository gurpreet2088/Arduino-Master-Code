#include <Keypad.h>

int Data[4];
int Master[4] ={1,2,3,4};  
byte data_count = 0;
char customKey;

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {4, 5, 6, 7}; 
byte colPins[COLS] = {8, 9, 10, 11}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  data_count = 0;
  Serial.begin(9600);
  Serial.print("Enter Password");
  Serial.println(" ");
  Serial.print("Pass: ");
  
}
  
void loop(){
  customKey = customKeypad.getKey();
  if (customKey){
  Data[data_count] = customKey;
  Serial.print(Data[data_count]);
  delay(100); 
  data_count++; 
  }
  if(data_count == 3){
    
    Serial.println(" ");
    Serial.println("You entered :");
    Serial.print(Data[4]);
    if(Data==Master){
      Serial.print("Correct"); 
      delay(5000);
      data_count = 0;
      }
    else{
      Serial.println(" ");
      Serial.print("Incorrect");
      delay(5000);
      data_count = 0;
      }
      
  }

}
