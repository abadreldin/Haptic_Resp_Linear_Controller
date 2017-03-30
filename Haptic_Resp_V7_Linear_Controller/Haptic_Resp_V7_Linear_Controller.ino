#include "Haptic_Resp_Linear_Controller.h"


void setup() {

  motorSetup();
  decoderSetup();
  timerSetup();
  
  Serial.begin (9600);

  setPwmFrequency(9, 1);
  //analogWrite(pwmPin, 127);
  desiredPosition = 180; //*radius;
  redPwmSpeed=0;
  //analogWrite(pwmPin, pwmSpeed);
  
  initPositionRed =0;
  sei();//allow interrupts 
  //cli();//stop interrupts
  pastVelocityRed = 0;
  startTime = micros();
  xBoundary = 30; //red motor is x
  yBoundary = 30; //blue motor is y
  redMotorDir = OUTWARD;
  setRedMotorSpeed(250, redMotorDir);
  findStartPosition();
  redPwmSpeed = 150;
  }

void loop() {

  //readSerialCommand();

  
  //Path Control
  //setMotorSpeed();

 
  //Haptic Interface - vibration
  /*if (actualPositionRed < xBoundary) {
    redMotorDir = INWARD;
    pwmSpeedRed = 100;
    setRedMotorSpeed(pwmSpeedRed, redMotorDir);
    delay(10);
    redMotorDir = OUTWARD;
    pwmSpeedRed = 200;
    setRedMotorSpeed(pwmSpeedRed, redMotorDir);
    delay(30);
  }
  else {
    redMotorDir = OFF;
    pwmSpeedRed = 0;
    setRedMotorSpeed(pwmSpeedRed, redMotorDir);
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
  
  //measure Step Response
 /* if(millis() > 200){
    redMotorDir = OFF;
    setRedMotorSpeed(0, redMotorDir);
  }/*
  else if(millis() > 850){
    redMotorDir = OUTWARD;
    setRedMotorSpeed(250, redMotorDir);
  }*/
  
  Serial.println (redActualPosition);
  //Serial.println (millis());
}

ISR(TIMER2_COMPA_vect){//timer2 interrupt 8kHz calculates position
    redActualPosition = computePositionRed();
}

ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz calculates position
    blueActualPosition = computePositionBlue();
}
