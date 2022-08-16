#include <LiquidCrystal.h>  // Include the LCD library
#include "DHT.h"           // Include the DHT library 

#define DHTPIN 10        // Where you have connected you DHT Sensor
#define DHTTYPE DHT11    // Defines the type of the sensor
//#define DHTTYPE DHT22    // Uncomment this line if you are using DHT22 sensor
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // LCD connection
void setup() {
  Serial.begin(9600);             // Begins serial communication
  Serial.println("Temperature");  // prints the message Temperature on the serial monitor

  dht.begin();                    // Begins the communications with the temperature sensor
  lcd.begin(16, 2);               // Begins the communication with the liquid crystal display

  lcd.print("Temperature");       // prints the message Temperature on the LCD
}

void loop() {
  
  float h = dht.readHumidity();         // reads the humidy and stores on the float variable named h
  float t = dht.readTemperature();      // reads the temperature and stores on the float variable named t

  Serial.print("Humidity: ");           // prints the message Humidity: on the serial monitor
  Serial.print(h);                      // prints the humidity value on the serial monitor
  Serial.print(" %\t");
  Serial.println();                     // goes to the next line on the serial monitor
 
  lcd.clear();                          // clears the LCD
  lcd.setCursor(0, 0);                  // sets the cursor on the first line
  lcd.print("Humidity:");               // prints the message Humidity: on the LCD
  lcd.setCursor(10, 0);                 // sets the cursor on the 10th column on the LCD
  lcd.print(h);                         // prints the humidity value on the LCD

  Serial.print("Temperature: ");        // prints the message Temperature: on the serial monitor 
  Serial.print(t);                      // prints the temperature value on the serial monitor
  Serial.print(" *C ");
  Serial.println();                     // goes to the next line on the serial monitor

  lcd.setCursor(0, 1);                  //sets the cursor on the bottom line on the LCD
  lcd.print("Temperature:");            //prints the message Temperature on the LCD
  lcd.setCursor(13, 1);                 //sets the cursor on the 13 column on the bottom
  lcd.print(t);                         //prints the temperature value on the lcd

  if (isnan(h) || isnan(t)) {                    //This if statement check to see if the DHT sensor is connected or disconnected
    Serial.println("Sensor is not connected");   //prints the message sensor is not connected on the serial monitor  
    lcd.clear();                                 // clears the lcd
    lcd.setCursor(0, 0);                         // sets the cursor on the first line on the lcd
    lcd.print("Sensor");                         // prints sensor on the lcd
    lcd.setCursor(0, 1);                         // sets the cursor on the bottom on the lcd
    lcd.print("Disconnected");                   // prints Disconnected on the lcd
    return;                                      // return from the if statement
  }

  delay(2000);                                  // wait for two seconds
}
