#include "Haptic_Resp_Linear_Controller.h"

void setup() {

  motorSetup();
  decoderSetup();
  timerSetup();
  
  Serial.begin (9600);

  //setPwmFrequency(9, 1);
  
  pastVelocityRed = 0;
  startTime = micros();
  //xBoundary = 50; //red motor is x
  //yBoundary = 50; //blue motor is y
  xBoundaryMin = 30; //red motor is x
  yBoundaryMin = 30; //blue motor is y
  xBoundaryMax = 80; //red motor is x
  yBoundaryMax = 80; //blue motor is y

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
  hapticSystem = MOTOROFF;
  //hapticSystemAction (hapticSystem);
  Serial.println("Please select a mode: SQUARE (1), CIRCLE (2), CORNER (3),");
  Serial.println("TRACEBACK (4), PATH (5), WELL (6), HILL (7)");   

  }

void loop() {

  //readSerialCommand();
 
  if (Serial.available()>0){
    buf[i]= Serial.read(); 
   
    if (int(buf[i])==13 || int(buf[i])==11 ){  //If Carriage return has been reached
     
      int result=atoi(buf);
      if (result > 7 || result < 1){
        Serial << " ERROR, please select a valid number" << "\n";
      }
      else{
        switch(result){
          case 1:
          Serial << "You have selected SQUARE mode" << "\n";
          hapticSystem = SQUARE;
          delay(2000);
          break;
          
          case 2:
          Serial << "You have selected CIRCLE mode" << "\n";
          hapticSystem = CIRCLE;
          delay(2000);
          break;
          
          case 3:
          Serial << "You have selected CORNER mode" << "\n";
          hapticSystem = CORNER;
          delay(2000);
          break;
          
          case 4:
          Serial << "You have selected TRACEBACK mode" << "\n";
          hapticSystem = TRACEBACK;
          delay(2000);
          break;

          case 5:
          Serial << "You have selected PATH mode" << "\n";
          hapticSystem = PATH;
          delay(2000);
          break;

          case 6:
          Serial << "You have selected WELL mode" << "\n";
          hapticSystem = WELL;
          delay(2000);
          break;

          case 7:
          Serial << "You have selected HILL mode" << "\n";
          hapticSystem = HILL;
          delay(2000);
          break;

          default:
          Serial << "You have selected OFF mode" << "\n";
          hapticSystem = MOTOROFF;
          delay(2000);
          break;
        
          
        }
      }
    
        
      for(int x=0;x<=3;x++){
        buf[x]=' ';
      }
      i=0;  //start over again
    } //if enter
     i++; 
    } //IF Serial.available

    hapticSystemAction (hapticSystem);

  /*blueMotorDir = OUTWARD;
  bluePwmSpeed = 200;
  setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);*/
  
  
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
  

  //Serial << "x = " << redActualPosition <<", y = " << blueActualPosition << "\n";
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
