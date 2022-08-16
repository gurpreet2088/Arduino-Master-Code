// Motor encoder output pulse per rotation
#define ENC_COUNT_REV 1856

// Encoder output to Arduino Interrupt pin
#define ENC_IN 3 

#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 6

// Pulse count from encoder
volatile long encoderValue = 0;
// One-second interval for measurements
int interval = 1000;

// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;

// Variable for RPM measuerment
int rpm = 0;

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600); 
  
  // Set encoder as input with internal pullup  
  pinMode(ENC_IN, INPUT_PULLUP); 

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.println("System is started.....");

  // Attach interrupt 
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);

  // Setup initial values for timer
  previousMillis = millis();
}

void loop()
{
  analogWrite(IN1, 140);//Left Motor
  analogWrite(IN2, 0);
  analogWrite(IN3, 0); // Right Motor
  analogWrite(IN4, 0); 

  // Update RPM value every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

    // Calculate RPM
    rpm = (float)(encoderValue * 60 / ENC_COUNT_REV);
    // Only update display when there is a reading
    if (rpm > 0) {
      Serial.print(" PULSES: ");
      Serial.print(encoderValue);
      Serial.print('\t');
      Serial.print(" SPEED: ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
  
    encoderValue = 0;
  }  
}

void updateEncoder()
{
  // Increment value for each pulse from encoder
  encoderValue++;
}
  
  
