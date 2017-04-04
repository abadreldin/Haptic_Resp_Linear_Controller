void motorSetup() {

  /*pinMode(blueMotorEn, OUTPUT);
  pinMode(blueMotorCoil1A, OUTPUT);
  pinMode(blueMotorCoil1B, OUTPUT);
  pinMode(blueMotorCoil2A, OUTPUT);
  pinMode(blueMotorCoil2B, OUTPUT);*/

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(7, HIGH);
  
  //set all motor control pins to outputs
  pinMode(redMotorEn, OUTPUT);
  pinMode(redMotorCoil1A, OUTPUT);
  pinMode(redMotorCoil1B, OUTPUT);
  pinMode(redMotorCoil2A, OUTPUT);
  pinMode(redMotorCoil2B, OUTPUT);

  

  //set both motor enable pins to high
  digitalWrite(redMotorEn, HIGH);
  //digitalWrite(blueMotorEn, HIGH);
  
}

//0= off 
//inward - redMotorCoil1 in direction 1 and redMotorCoil2 in direction 1
//outward - redMotorCoil1 in direction 2 and redMotorCoil2 in direction 2
//where direction 0 = off, direction 1: pinA=HIGH, pinB= LOW, and direction 2: pinA=LOW and pinB=HIGH
//where coil 1 refers to pins redMotorCoil1A 1, and redMotorCoil1B and coil 2 refers to redMotorCoil2A 1, and redMotorCoil2B


void setBlueMotorSpeed( int bluePwm, directions blueMotorDir){
  
  /*switch(blueMotorDir){
    case OUTWARD:
      //redMotorCoil1 in direction 1
      analogWrite(blueMotorCoil1A, bluePwm);
      analogWrite(blueMotorCoil1B, LOW);

      //redMotorCoil2 in direction 2
      analogWrite(blueMotorCoil2A, bluePwm);
      analogWrite(blueMotorCoil2B, LOW);
      break;
      
    case INWARD:
      //redMotorCoil1 in direction 2
      analogWrite(blueMotorCoil1A, LOW);
      analogWrite(blueMotorCoil1B, bluePwm);

      //redMotorCoil2 in direction 1
      analogWrite(blueMotorCoil2A, LOW);
      analogWrite(blueMotorCoil2B, bluePwm);
      break;
      
    
    case OFF: //off
      //redMotorCoil1 in direction 0
      analogWrite(blueMotorCoil1A, LOW);
      analogWrite(blueMotorCoil1B, LOW);

      //redMotorCoil2 in direction 0
      analogWrite(blueMotorCoil2A, LOW);
      analogWrite(blueMotorCoil2B, LOW);
      break;
      
  }*/
  switch(blueMotorDir){
    case OUTWARD:
      //redMotorCoil1 in direction 1
      analogWrite(11, bluePwm);
      analogWrite(10, LOW);

      //redMotorCoil2 in direction 2
      analogWrite(9, bluePwm);
      analogWrite(8, LOW);
      break;
      
    case INWARD:
      //redMotorCoil1 in direction 2
      analogWrite(11, LOW);
      analogWrite(10, bluePwm);

      //redMotorCoil2 in direction 1
      analogWrite(9, LOW);
      analogWrite(8, bluePwm);
      break;
      
    
    case OFF: //off
      //redMotorCoil1 in direction 0
      analogWrite(11, LOW);
      analogWrite(10, LOW);

      //redMotorCoil2 in direction 0
      analogWrite(9, LOW);
      analogWrite(8, LOW);
      break;
      
  }
}

void setRedMotorSpeed( int redPwm, directions redMotorDir){
  
  switch(redMotorDir){
    case OUTWARD:
      //redMotorCoil1 in direction 1
      analogWrite(redMotorCoil1A, redPwm);
      analogWrite(redMotorCoil1B, LOW);

      //redMotorCoil2 in direction 2
      analogWrite(redMotorCoil2A, redPwm);
      analogWrite(redMotorCoil2B, LOW);
      break;
      
    case INWARD:
      //redMotorCoil1 in direction 2
      analogWrite(redMotorCoil1A, LOW);
      analogWrite(redMotorCoil1B, redPwm);

      //redMotorCoil2 in direction 1
      analogWrite(redMotorCoil2A, LOW);
      analogWrite(redMotorCoil2B, redPwm);
      break;
      
    
    case OFF: //off
      //redMotorCoil1 in direction 0
      analogWrite(redMotorCoil1A, LOW);
      analogWrite(redMotorCoil1B, LOW);

      //redMotorCoil2 in direction 0
      analogWrite(redMotorCoil2A, LOW);
      analogWrite(redMotorCoil2B, LOW);
      break;
     
  }
}



