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
          //Serial << "You have selected SQUARE mode" << "\n";
          hapticSystem = SQUARE;
          delay(2000);
          break;
          
          case 2:
          //Serial << "You have selected CIRCLE mode" << "\n";
          hapticSystem = CIRCLE;
          delay(2000);
          break;
          
          
          //setupPosition(40,40);

          
          case 4:
          //Serial << "You have selected TRACEBACK mode" << "\n";
          hapticSystem = TRACEBACK;
         // setupPosition(40,40);
          myPIDRED.SetMode(AUTOMATIC);
          myPIDBLUE.SetMode(AUTOMATIC);

          delay(2000);
          break;

          case 5:
          //Serial << "You have selected PATH mode" << "\n";
          hapticSystem = PATH;
          finished= FALSE;
          index = 0;
          

          //turn the PID on
          myPIDRED.SetMode(AUTOMATIC);
          myPIDBLUE.SetMode(AUTOMATIC);
          delay(2000);
          break;

          case 6:
          //Serial << "You have selected WELL mode" << "\n";
          hapticSystem = WELL;
          delay(2000);
          index =0;
          break;

          case 7:
          //Serial << "You have selected HILL mode" << "\n";
          hapticSystem = DIAGONALALLEY;
          delay(2000);
          break;

          case 8:
          //Serial << "You have selected INNERSQUARE mode" << "\n";
          hapticSystem = INNERSQUARE;
          //setupPosition(40,40);
          delay(2000);
          break;

          case 9:
          //Serial << "You have selected HARDSQUARE mode" << "\n";
          hapticSystem = HARDSQUARE;
          //setupPosition(40,40);
          delay(2000);
          break;


          case 3:
          //Serial << "You have selected CORNSTARCH WALL mode" << "\n";
          hapticSystem = CORNSTARCHWALL;
          //setupPosition(0,0);
          delay(2000);
          break;
          
          case 0:
          //Serial << "You have selected OFF mode" << "\n";
          hapticSystem = MOTOROFF;
          delay(2000);
          break;

          /*case 7:
          hapticSystem = BARRIER;
          break;*/
        
          
        }
  }
    hapticSystemAction (hapticSystem);
 
    //if (micros()%50000 < 333) // if (millis()% 60 <10)
      //Serial << redActualPosition <<" " << blueActualPosition << "\n";
}
ISR(TIMER5_COMPA_vect){//timer1 interrupt 2kHz calculates position
    blueActualPosition = computePositionBlue();
    redActualPosition = computePositionRed();
}

/*ISR(TIMER2_COMPA_vect){//timer2 interrupt 8kHz calculates position
    redActualPosition = computePositionRed();
}*/

/*ISR(TIMER5_COMPA_vect){//timer0 interrupt 2kHz calculates position
    Serial << redActualPosition <<" " << blueActualPosition << "\n";
}*/
