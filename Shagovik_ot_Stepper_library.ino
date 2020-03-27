/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200
const int enPin = 8; 
const int stepPin = 7; 
const int dirPin = 6; 
const int slpPin = 5; 
const int rstPin = 4; 
const int MS1Pin = 9;
const int MS2Pin = 10;
const int MS3Pin = 11;
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, dirPin, stepPin);

// the previous reading from the analog input
int previous = 0;

void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(slpPin,OUTPUT); 
  pinMode(rstPin,OUTPUT);
  pinMode(MS1Pin,OUTPUT); 
  pinMode(MS2Pin,OUTPUT);
  pinMode(MS3Pin,OUTPUT);
  digitalWrite(MS1Pin,LOW); 
  digitalWrite(MS2Pin,LOW); 
  digitalWrite(MS3Pin,LOW); 
  digitalWrite(slpPin,HIGH); 
  digitalWrite(rstPin,HIGH); 
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(200);
}

void loop() {
  // get the sensor value
  int val = 100;

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(100);

  // remember the previous value of the sensor
  previous = val;
}
