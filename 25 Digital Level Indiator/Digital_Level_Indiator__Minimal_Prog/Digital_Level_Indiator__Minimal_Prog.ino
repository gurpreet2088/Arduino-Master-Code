// minimal MPU-6050 tilt and roll (sjr)
// works perfectly with GY-521, pitch and roll signs agree with arrows on sensor module 7/2019
// tested with eBay Pro Mini, **no external pullups on SDA and SCL** (works with internal pullups!)
//
#include<Wire.h>
const int MPU_addr1 = 0x68;
float xa, ya, za, roll, pitch;

// Level LEDs

int levelLED_neg0 = 10;
int levelLED_level = 9;
int levelLED_pos0 = 8;

void setup() {

  Wire.begin();                                      //begin the wire communication
  Wire.beginTransmission(MPU_addr1);                 //begin, send the slave adress (in this case 68)
  Wire.write(0x6B);                                  //make the reset (place a 0 into the 6B register)
  Wire.write(0);
  Wire.endTransmission(true);                        //end the transmission
  Serial.begin(9600);

// Set Level LEDs as outputs
  pinMode(levelLED_neg0, OUTPUT);
  pinMode(levelLED_level, OUTPUT);
  pinMode(levelLED_pos0, OUTPUT);
  
}

void loop() {

  Wire.beginTransmission(MPU_addr1);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr1, 6, true); //get six bytes accelerometer data

  xa = Wire.read() << 8 | Wire.read();
  ya = Wire.read() << 8 | Wire.read();
  za = Wire.read() << 8 | Wire.read();

  roll = atan2(ya , za) * 180.0 / PI;
  pitch = atan2(-xa , sqrt(ya * ya + za * za)) * 180.0 / PI;

  Serial.print("roll = ");
  Serial.print(roll,1);
  Serial.print(", pitch = ");
  Serial.println(pitch,1);

   if (roll < -5.1) {
    // Turn on Level LED
    digitalWrite(levelLED_neg0, HIGH);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos0, LOW);
        
    } else if ((roll < 5.0) && (roll > -5.0)) {
    // Turn on Level LED
    digitalWrite(levelLED_neg0, LOW);
    digitalWrite(levelLED_level, HIGH);
    digitalWrite(levelLED_pos0, LOW);
        
    } else if (roll > 5.1) {
    // Turn on Level LED
    digitalWrite(levelLED_neg0, LOW);
    digitalWrite(levelLED_level, LOW);
    digitalWrite(levelLED_pos0, HIGH);
    
    
    }
  delay(400);
}
