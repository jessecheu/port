#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 27
#define IN2 13
#define IN3 33
#define IN4 12

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed at 5 rpm
  myStepper.setSpeed(5);
  // initialize the serial port
  Serial.begin(115200);
}

void loop() {
  // step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}

