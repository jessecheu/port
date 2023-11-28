#include <AccelStepper.h>
#include <MultiStepper.h>

// Define the stepper motor and the pins that is connected to
AccelStepper stepper1(1, 39, 34); // (Typeof driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 32, 35);

MultiStepper steppersControl;  // Create instance of MultiStepper

long gotoposition[2]; // An array to store the target positions for each stepper motor

void setup() {

  stepper1.setMaxSpeed(1000); // Set maximum speed value for the stepper
  stepper2.setMaxSpeed(1000);


  // Adding the 3 steppers to the steppersControl instance for multi stepper control
  steppersControl.addStepper(stepper1);
  steppersControl.addStepper(stepper2);
}

void loop() {
  // Store the target positions in the "gotopostion" array
  gotoposition[0] = 200;  // 800 steps - full rotation with quater-step resolution
  gotoposition[1] = 400;

  steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
  steppersControl.runSpeedToPosition(); // Blocks until all steppers are in position

  delay(1000);

  gotoposition[0] = 0;
  gotoposition[1] = 0;

  steppersControl.moveTo(gotoposition);
  steppersControl.runSpeedToPosition();

  delay(1000);
}