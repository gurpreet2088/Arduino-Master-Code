/******************************************************************************
File name:   Processing_Potentiometer.pde
Description: Arduino and processing interactive
             The size of the potentiometer voltage control red circle on the PC 
Website: www.quadstore.in
********************************************************************************/ 
import processing.serial.*; 
  
Serial serial;   
int sensorValue; 

void setup() { 
  // set the canvas size is 400 x 400
  size(400, 400);  
  
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM26, here please
  // adjust according to actual situation.
  serial = new Serial(this, "COM26", 9600); 
} 
  
void draw() { 
  if ( serial.available() > 0) { 
    // Read from serial production sensor value.
    sensorValue = serial.read();  
    println(sensorValue); //Print out the processing received sensor value
  
    // Draw a circle on canvas
    background(255); // Background to white
    fill(0,0,255);   // Within the circle fill in blue
    ellipse(200, 200, sensorValue, sensorValue); //In point(200,200) as the center circle
  }   
} 
