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
const int Run_Button_pin = 12;
const int Relay_pin = 13;

int stage;
long photo_time = 1000;
int photo_clicks = 10;

Stepper stepper(STEPS, dirPin, stepPin);

// the previous reading from the analog input
int previous = 0;

void setup() {
  pinMode(Run_Button_pin,INPUT_PULLUP);
  pinMode(Relay_pin,OUTPUT);
  digitalWrite(Relay_pin,HIGH);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(slpPin,OUTPUT); 
  pinMode(rstPin,OUTPUT);
  pinMode(MS1Pin,OUTPUT); 
  pinMode(MS2Pin,OUTPUT);
  pinMode(MS3Pin,OUTPUT);
  digitalWrite(MS1Pin,HIGH); 
  digitalWrite(MS2Pin,HIGH); 
  digitalWrite(MS3Pin,HIGH); 
  digitalWrite(slpPin,LOW); 
  digitalWrite(rstPin,HIGH); 
  
  stepper.setSpeed(200);
  
}

void loop() {
  
  
  if (!digitalRead(Run_Button_pin)){
    stage = 100;
  }
  

  if(stage==100){
    for (int i = 1; i <= photo_clicks; i++) {
      digitalWrite(Relay_pin,LOW);
      delay(500);
      digitalWrite(Relay_pin,HIGH);
      delay(500);
      digitalWrite(slpPin,HIGH);
      stepper.step(16*4*STEPS/photo_clicks);
      digitalWrite(slpPin,LOW);
      delay(photo_time);
    }
    stage = 0;
  }
  
}
