#include "Haptic_Resp_Linear_Controller.h"

void setup() {

  motorSetup();
  decoderSetup();
  timerSetup();
  
  Serial.begin (9600);
  
  //xBoundary = 50; //red motor is x
  //yBoundary = 50; //blue motor is y
  xBoundaryMin = 25; //red motor is x
  yBoundaryMin = 25; //blue motor is y
  xBoundaryMax = 55; //red motor is x
  yBoundaryMax = 55; //blue motor is y

  xBoundaryMin2 = 15; //red motor is x
  yBoundaryMin2 = 15; //blue motor is y
  xBoundaryMax2 = 65; //red motor is x
  yBoundaryMax2 = 65; //blue motor is y

  sei();//allow interrupts 
  //cli();//stop interrupts
  findStartPosition();
  hapticSystem = MOTOROFF;
  hapticSystemAction (hapticSystem);

  index=0;
  InputRed = redActualPosition;
  InputBlue = blueActualPosition;
  SetpointRed = redSetPath[index];
  SetpointBlue= blueSetPath[index];
  
  }

void loop() {

  if (Serial.available()>0){
    result = Serial.read() - '0';
        switch(result){
          case 1:
          hapticSystem = SQUARE;
          delay(1000);
          break;
          
          case 2:
          hapticSystem = CIRCLE;
          delay(1000);
          break;
          
          
          case 4:
          hapticSystem = TRACEBACK;
          delay(1000);
          break;

          case 5:
          hapticSystem = PATH;
          finished= FALSE;
          index = 0;
          delay(1000);
          break;

          case 6:
          hapticSystem = WELL;
          delay(1000);
          index =0;
          break;

          case 7:
          hapticSystem = DIAGONALALLEY;
          delay(1000);
          break;

          case 8:
          hapticSystem = INNERSQUARE;
          delay(1000);
          break;

          case 9:
          hapticSystem = HARDSQUARE;
          //setupPosition(40,40);
          delay(1000);
          break;

          case 3:
          hapticSystem = CORNSTARCHWALL;
          delay(1000);
          break;
          
          case 0:
          hapticSystem = MOTOROFF;
          delay(1000);
          break;

        }
  }
    hapticSystemAction (hapticSystem);
 
}
ISR(TIMER5_COMPA_vect){//timer1 interrupt 2kHz calculates position
    blueActualPosition = computePositionBlue();
    redActualPosition = computePositionRed();
}

