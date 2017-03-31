#include "Haptic_Resp_Linear_Controller.h"

void setup() {

  motorSetup();
  decoderSetup();
  timerSetup();
  
  Serial.begin (9600);

  //setPwmFrequency(9, 1);
  
  pastVelocityRed = 0;
  startTime = micros();
  xBoundary = 50; //red motor is x
  yBoundary = 50; //blue motor is y

  // Start with motors off
  redPwmSpeed = 0;
  redMotorDir = OFF;
  setRedMotorSpeed(redPwmSpeed, redMotorDir);
  
  bluePwmSpeed = 0;
  blueMotorDir = OFF;
  setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);

  sei();//allow interrupts 
  //cli();//stop interrupts
  findStartPosition();
  }

void loop() {

  //Serial.println (redPositionArr[8]);
  /*Serial.println (digitalRead(bluePositionPin7));
  Serial.println (digitalRead(bluePositionPin6));
  Serial.println (digitalRead(bluePositionPin5));
  Serial.println (digitalRead(bluePositionPin4));
  Serial.println (digitalRead(bluePositionPin3));
  Serial.println (digitalRead(bluePositionPin2));
  Serial.println (digitalRead(bluePositionPin1));
  Serial.println (digitalRead(bluePositionPin0));
  delay(5000);*/
  //readSerialCommand();
  //bluePwmSpeed = 250;
  //blueMotorDir = INWARD;
  //setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
  
  //redMotorDir = OUTWARD;
  //setRedMotorSpeed(250, redMotorDir);

  //Path Control
  //setMotorSpeed();

 
  //Haptic Interface - vibration
  if (redActualPosition >= xBoundary) {
    redMotorDir = INWARD;
    redPwmSpeed = 100;
    setRedMotorSpeed(redPwmSpeed, redMotorDir);
    delay(10);
    redMotorDir = OUTWARD;
    redPwmSpeed = 200;
    setRedMotorSpeed(redPwmSpeed, redMotorDir);
    delay(30);
  }
  else {
    redMotorDir = OFF;
    redPwmSpeed = 0;
    setRedMotorSpeed(redPwmSpeed, redMotorDir);
  }
  if (blueActualPosition >= xBoundary) {
    blueMotorDir = INWARD;
    bluePwmSpeed = 100;
    setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
    delay(10);
    blueMotorDir = OUTWARD;
    bluePwmSpeed = 200;
    setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
    delay(30);
  }
  else {
    blueMotorDir = OFF;
    bluePwmSpeed = 0;
    setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);p
  }
   
  
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
  
  //Serial.println (blueActualPosition);
  Serial.println (redActualPosition);
  //delay(100);
  //Serial.println (millis());
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 2kHz calculates position
    blueActualPosition = computePositionBlue();
    redActualPosition = computePositionRed();
}

/*ISR(TIMER2_COMPA_vect){//timer2 interrupt 8kHz calculates position
    redActualPosition = computePositionRed();
}

ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz calculates position
    blueActualPosition = computePositionBlue();
}*/
