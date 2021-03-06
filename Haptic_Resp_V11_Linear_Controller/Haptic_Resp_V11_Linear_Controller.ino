#include "Haptic_Resp_Linear_Controller.h"

void setup() {

  motorSetup();
  decoderSetup();
  timerSetup();
  
  Serial.begin (9600);

  //setPwmFrequency(9, 1);
  
  //xBoundary = 50; //red motor is x
  //yBoundary = 50; //blue motor is y
  xBoundaryMin = 30; //red motor is x
  yBoundaryMin = 30; //blue motor is y
  xBoundaryMax = 60; //red motor is x
  yBoundaryMax = 60; //blue motor is y

  // Start with motors off
  /*redPwmSpeed = 0;
  redMotorDir = OFF;
  setRedMotorSpeed(redPwmSpeed, redMotorDir);
  */
  //bluePwmSpeed = 250;
  //blueMotorDir = OUTWARD;
  //setBlueMotorSpeed(250, blueMotorDir);

  sei();//allow interrupts 
  //cli();//stop interrupts
  findStartPosition();
  hapticSystem = MOTOROFF;
  hapticSystemAction (hapticSystem);
  //Serial.println("Please select a mode: SQUARE (1), CIRCLE (2), CORNER (3),");
  //Serial.println("TRACEBACK (4), PATH (5), WELL (6), HILL (7)");   
  //Serial.println("INNER SQUARE (8), OUTER SQUARE (9), CORNSTARCH WALL (10), BUTTON (11)");
  
  }

void loop() {
  //setRedMotorSpeed(150, OUTWARD);
  //readSerialCommand();
 
  if (Serial.available()>0){
    buf[i]= Serial.read(); 
   
    if (int(buf[i])==13 || int(buf[i])==11 ){  //If Carriage return has been reached
     
      int result=atoi(buf);
      if (result > 10 || result < 1){
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

          case 8:
          Serial << "You have selected INNERSQUARE mode" << "\n";
          hapticSystem = INNERSQUARE;
          delay(2000);
          break;

          case 9:
          Serial << "You have selected OUTERSQUARE mode" << "\n";
          hapticSystem = OUTERSQUARE;
          delay(2000);
          break;

          /*case 10:
          Serial << "You have selected BUTTON mode" << "\n";
          hapticSystem = BUTTON;
          delay(2000);
          break;*/

          case 10:
          Serial << "You have selected CORNSTARCH WALL mode" << "\n";
          hapticSystem = CORNSTARCHWALL;
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
    
    printCounter ++;
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 2kHz calculates position
    blueActualPosition = computePositionBlue();
    redActualPosition = computePositionRed();
}

/*ISR(TIMER2_COMPA_vect){//timer2 interrupt 8kHz calculates position
    redActualPosition = computePositionRed();
}*/

/*ISR(TIMER5_COMPA_vect){//timer0 interrupt 2kHz calculates position
    Serial << redActualPosition <<" " << blueActualPosition << "\n";
}*/
