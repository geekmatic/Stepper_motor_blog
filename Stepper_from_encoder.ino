#include <TimerOne.h>

int pinDIR = 6;
int pinSTEP = 7;

int pinA = 2;  // номер вывода, подключенный к CLK енкодера
int pinB = 3;  // номер вывода контроллера, подключенный к DT енкодера
int encoderPosCount = 0; 
int pinALast;  

int pinSLEEP = 5;
int pinRES = 4;
int pinEN = 8;
int MS1Pin = 9;
int MS2Pin = 10;
int MS3Pin = 11;
int countime;
volatile byte x;
byte CW;

void setup()
{
  pinMode(pinSLEEP, OUTPUT);
  pinMode(pinRES, OUTPUT);
  pinMode(pinDIR, OUTPUT);
  pinMode(pinSTEP, OUTPUT);
  pinMode(pinEN, OUTPUT);
  pinMode(MS1Pin,OUTPUT); 
  pinMode(MS2Pin,OUTPUT);
  pinMode(MS3Pin,OUTPUT);
  digitalWrite(MS1Pin,HIGH); 
  digitalWrite(MS2Pin,HIGH); 
  digitalWrite(MS3Pin,HIGH); 
  digitalWrite(pinEN,LOW);
  digitalWrite(pinRES,HIGH);
  digitalWrite(pinSLEEP,HIGH);

  pinMode (pinA,INPUT);
  pinMode (pinB,INPUT);
  pinALast = digitalRead(pinA);
  attachInterrupt(digitalPinToInterrupt(2), doEncoderA, CHANGE);
  Serial.begin(9600);
  
  Timer1.initialize(20);
  Timer1.attachInterrupt(func_blink);
}

void loop()
{
  if(countime>5) PORTB |= 1 << 0;
  countime++;
  delay(100);
}

void doEncoderA() {
  if (pinALast != (PIND >> 2 & 1)){
    if ((PIND >> 2 & 1) == HIGH) {
    
      if ((PIND >> 3 & 1) == LOW) {
        encoderPosCount ++;         // CW
        CW=1;
      }
    else {
      encoderPosCount--;         // CCW
      CW=0;
    }
    countime = 0;
  }
  else
  {
    if ((PIND >> 3 & 1) == HIGH) {
      encoderPosCount ++;          // CW
      CW=1;
    }
    else {
      encoderPosCount--;        // CCW
      CW=0;
    }
    countime = 0;

  }
    PORTB &=~(1 << 0);
      if(CW==1) {
        PORTD |=(1 << 6);
        x=254;
      }
      else {
        PORTD &=~(1 << 6);
        x=254;
      }
      
  }
  pinALast = (PIND >> 2 & 1);
}

void func_blink(void)
{
  if (x > 0) {
    x --;
    PORTD ^= 1 << 7;
  }
  
}

