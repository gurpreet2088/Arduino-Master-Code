// Motor encoder output pulse per rotation
#define ENC_COUNT_REV 1856

// Encoder output to Arduino Interrupt pin
#define R_ENC_IN 2 
#define L_ENC_IN 3

#define IN1 9
#define IN2 6
#define IN3 11
#define IN4 10

// Pulse count from encoder
volatile long rightencoderValue = 0;
volatile long leftencoderValue = 0;
// One-second interval for measurements
int interval = 1000;

// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;

// Variable for right_rpm measuerment
int right_rpm = 0;
int left_rpm = 0;

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600); 
  
  // Set encoder as input with internal pullup  
  pinMode(R_ENC_IN, INPUT_PULLUP); 
  pinMode(L_ENC_IN, INPUT_PULLUP);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.println("System is started.....");

  // Attach interrupt 
  attachInterrupt(digitalPinToInterrupt(R_ENC_IN), updateRightEncoder, RISING);
  attachInterrupt(digitalPinToInterrupt(L_ENC_IN), updateLeftEncoder, RISING);

  // Setup initial values for timer
  previousMillis = millis();
}

void loop()
{
  analogWrite(IN1, 255);//Left Motor
  analogWrite(IN2, 0);
  analogWrite(IN3, 255); // Right Motor
  analogWrite(IN4, 0); 

  // Update right_rpm value every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

    // Calculate right_rpm
    right_rpm = (float)(rightencoderValue * 60 / ENC_COUNT_REV);
    left_rpm = (float)(leftencoderValue * 60 / ENC_COUNT_REV);
    // Only update display when there is a reading
    if (right_rpm > 0  || left_rpm > 0) {
      Serial.print(" Left PULSES: ");
      Serial.print(leftencoderValue);
      Serial.print('\t');
      Serial.print(" Right PULSES: ");
      Serial.print(rightencoderValue);
      Serial.println();

      Serial.print(" Left SPEED: ");
      Serial.print(left_rpm);
      Serial.print('\t');
      Serial.print('\t');
      Serial.print(" Right SPEED: ");
      Serial.print(right_rpm);
      Serial.println();
    }
  
    rightencoderValue = 0;
    leftencoderValue = 0;
  }  
}

void updateRightEncoder()
{
  // Increment value for each pulse from encoder
  rightencoderValue++;
}

void updateLeftEncoder()
{
  // Increment value for each pulse from encoder
  leftencoderValue++;
}
  
  
