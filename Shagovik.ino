const int enPin = 8; 
const int stepPin = 7; 
const int dirPin = 6; 
const int slpPin = 5; 
const int rstPin = 4; 
const int MS1Pin = 9;
const int MS2Pin = 10;
const int MS3Pin = 11;
 
void setup() {
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
  digitalWrite(slpPin,HIGH); 
  digitalWrite(rstPin,HIGH); 
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(200); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(200);
    delay(1); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(200);
    delay(1);
  }
  delay(1000);
}
