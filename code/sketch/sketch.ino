#include <Wire.h>
#define WHEEL_SENSOR 11 
#define DECAPPING_SENSOR 10 
#define DECAPPING_MOTOR 13 
#define TURNER_DIRPIN 5 
#define TURNER_STEPPIN 2 
#define TURNER_ENABLE 8 
#define START_STOP_BUTTON 9
#define TURN_MOTOR_SPEED 1200 

bool systemRunning = false;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(WHEEL_SENSOR, INPUT_PULLUP);
  pinMode(DECAPPING_SENSOR, INPUT_PULLUP);
  pinMode(START_STOP_BUTTON, INPUT_PULLUP);
  pinMode(DECAPPING_MOTOR, OUTPUT);
   
  pinMode(TURNER_DIRPIN, OUTPUT);
  pinMode(TURNER_STEPPIN, OUTPUT);
  pinMode(TURNER_ENABLE, OUTPUT);

  digitalWrite(DECAPPING_MOTOR, LOW); 
  digitalWrite(TURNER_ENABLE, LOW); // stepper
  digitalWrite(TURNER_DIRPIN, LOW); // Set direction
  
  // --- INITIAL INDEXING PHASE ---
  indexHardware();
  Serial.println("System Ready. Press Button to Start.");
}

void loop() {
  checkButton();
  // 1. Rotate Wheel until sensor hit
  if (systemRunning) {
  rotateWheelToSensor();
  // 2. Run Decapper until sensor hit
  if(!systemRunning) return;
  runDecapperToSensor();
  // Small pause for stability
  delay(500); 
  }else {
    digitalWrite(TURNER_ENABLE, LOW); // Disable Stepper when stopped
    digitalWrite(DECAPPING_MOTOR, LOW); // Ensure decapper is off
  }
}

void checkButton() {
  bool currentButtonState = digitalRead(START_STOP_BUTTON);
  
  // Detect button press (Transition from HIGH to LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    systemRunning = !systemRunning; // Toggle state
    Serial.print("System Running: ");
    Serial.println(systemRunning ? "ON" : "OFF");
    delay(200); // Simple debounce
  }
  lastButtonState = currentButtonState;
}

// Moves the stepper until the limit switch is triggered
void rotateWheelToSensor() {
  // Move off the sensor first if it's already triggered
while(digitalRead(WHEEL_SENSOR) == HIGH) {
    stepMotor();
  }
  // Move until it hits the sensor
  while(digitalRead(WHEEL_SENSOR) == LOW) {
    stepMotor();
  }
}

// Runs DC motor until the decapping limit switch is triggered
void runDecapperToSensor() {
  if(digitalRead(WHEEL_SENSOR) == HIGH){
  digitalWrite(DECAPPING_MOTOR, HIGH);
  delay(800);
  while(digitalRead(DECAPPING_SENSOR) == LOW) {
    digitalWrite(DECAPPING_MOTOR, HIGH);
  }
  digitalWrite(DECAPPING_MOTOR, LOW);
  }
}

void stepMotor() {
  digitalWrite(TURNER_STEPPIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TURNER_STEPPIN, LOW);
  delayMicroseconds(TURN_MOTOR_SPEED);
}

void indexHardware() {
  // Logic to home both components on startup
  rotateWheelToSensor();
  delay(2000);
  runDecapperToSensor();
}
