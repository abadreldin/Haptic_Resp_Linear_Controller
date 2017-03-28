// Timer0 for Blue Motor position, Timer2 for Red Motor position

#include "Haptic_Resp_Linear_Controller.h"

int i=0;
char buf[3];

void setup() {

  pinMode(latchPin, OUTPUT); 
  pinMode(positionPin0, INPUT); 
  pinMode(positionPin1, INPUT); 
  pinMode(positionPin2, INPUT); 
  pinMode(positionPin3, INPUT); 
  pinMode(positionPin4, INPUT); 
  pinMode(positionPin5, INPUT); 
  pinMode(positionPin6, INPUT); 
  pinMode(positionPin7, INPUT); 
  //pinMode(positionPin8, INPUT); 
  pinMode(directionPin, INPUT); 
  pinMode(SEL1, OUTPUT);
  pinMode(SEL2, OUTPUT);
  pinMode(resetPin, OUTPUT);
  
  digitalWrite(resetPin,LOW);
  delay(100);
  digitalWrite(resetPin,HIGH);
  digitalWrite(latchPin, HIGH);

  Serial.begin (9600);

  //set timer0 interrupt at 2kHz
  /*TCCR0A = 0;// set entire TCCR2A register to 0
  TCCR0B = 0;// same for TCCR2B
  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);*/

  //set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);

  setPwmFrequency(9, 1);
  //analogWrite(pwmPin, 127);
  desiredPosition = 180; //*radius;
  pwmSpeed=0;
  //analogWrite(pwmPin, pwmSpeed);
  
  initPosition =0;
  sei();//allow interrupts 
  //cli();//stop interrupts
  pastVelocity = 0;
  startTime = micros();
  setupMotor();
  wall = 50;
  redMotorDir = OFF;
  setRedMotorSpeed(0, redMotorDir);
  }

void loop() {

  readSerialCommand();
  
  //Path Control
  //setMotorSpeed();

  //Step Response Computation
  

  //Haptic Interface
  /*if (actualPosition < wall) {
    redMotorDir = INWARD;
    setRedMotorSpeed(100, redMotorDir);
    delay(10);
    redMotorDir = OUTWARD;
    setRedMotorSpeed(200, redMotorDir);
    delay(30);
  }
  else {
    redMotorDir = OFF;
    setRedMotorSpeed(0, redMotorDir);
  }*/

  
  //Haptic Control
  //Serial.println (velocity);
  /*startTime = micros();
  tempActualPosition = actualPosition;
  velocity = (abs(tempActualPosition - initPosition))/(micros()-startTime); //degToRad*1000000;
  Serial.println (velocity,6);
  initPosition = tempActualPosition;
  //setMotorSpeedHaptic(velocity);
  delay(10);*/
  
  //measure position
  //Serial.println (actualPosition);
  //Serial.println (millis());
}

ISR(TIMER2_COMPA_vect){//timer2 interrupt 8kHz calculates position
    actualPosition = computePosition();
}

/*ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz calculates position
    velocity = computeVelocity();
}*/
