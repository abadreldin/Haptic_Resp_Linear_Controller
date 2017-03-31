void motorSetup() {

  //set all motor control pins to outputs
  pinMode(redMotorEn, OUTPUT);
  pinMode(redMotorCoil1A, OUTPUT);
  pinMode(redMotorCoil1B, OUTPUT);
  pinMode(redMotorCoil2A, OUTPUT);
  pinMode(redMotorCoil2B, OUTPUT);

  pinMode(blueMotorEn, OUTPUT);
  pinMode(blueMotorCoil1A, OUTPUT);
  pinMode(blueMotorCoil1B, OUTPUT);
  pinMode(blueMotorCoil2A, OUTPUT);
  pinMode(blueMotorCoil2B, OUTPUT);

  //set both motor enable pins to high
  digitalWrite(redMotorEn, HIGH);
  digitalWrite(blueMotorEn, HIGH);
}

//0= off 
//inward - redMotorCoil1 in direction 1 and redMotorCoil2 in direction 1
//outward - redMotorCoil1 in direction 2 and redMotorCoil2 in direction 2
//where direction 0 = off, direction 1: pinA=HIGH, pinB= LOW, and direction 2: pinA=LOW and pinB=HIGH
//where coil 1 refers to pins redMotorCoil1A 1, and redMotorCoil1B and coil 2 refers to redMotorCoil2A 1, and redMotorCoil2B

void setRedMotorSpeed( int redPwm, directions redMotorDir){
  
  switch(redMotorDir){
    case INWARD:
      //redMotorCoil1 in direction 1
      analogWrite(redMotorCoil1A, redPwmSpeed);
      analogWrite(redMotorCoil1B, LOW);

      //redMotorCoil2 in direction 2
      analogWrite(redMotorCoil2A, redPwmSpeed);
      analogWrite(redMotorCoil2B, LOW);
      break;
      
    case OUTWARD:
      //redMotorCoil1 in direction 2
      analogWrite(redMotorCoil1A, LOW);
      analogWrite(redMotorCoil1B, redPwmSpeed);

      //redMotorCoil2 in direction 1
      analogWrite(redMotorCoil2A, LOW);
      analogWrite(redMotorCoil2B, redPwmSpeed);
      break;
      
    
    case OFF: //off
      //redMotorCoil1 in direction 0
      analogWrite(redMotorCoil1A, LOW);
      analogWrite(redMotorCoil1B, LOW);

      //redMotorCoil2 in direction 0
      analogWrite(redMotorCoil2A, LOW);
      analogWrite(redMotorCoil2B, LOW);
      break;
      
    default: //off
      //redMotorCoil1 in direction 0
      analogWrite(redMotorCoil1A, LOW);
      analogWrite(redMotorCoil1B, LOW);

      //redMotorCoil2 in direction 0
      analogWrite(redMotorCoil2A, LOW);
      analogWrite(redMotorCoil2B, LOW);
      break;
  }
}



void setBlueMotorSpeed( int bluepwm, directions blueMotorDir){
  
  switch(blueMotorDir){
    case INWARD:
      //redMotorCoil1 in direction 1
      analogWrite(blueMotorCoil1A, bluePwmSpeed);
      analogWrite(blueMotorCoil1B, LOW);

      //redMotorCoil2 in direction 2
      analogWrite(blueMotorCoil2A, bluePwmSpeed);
      analogWrite(blueMotorCoil2B, LOW);
      break;
      
    case OUTWARD:
      //redMotorCoil1 in direction 2
      analogWrite(blueMotorCoil1A, LOW);
      analogWrite(blueMotorCoil1B, bluePwmSpeed);

      //redMotorCoil2 in direction 1
      analogWrite(blueMotorCoil2A, LOW);
      analogWrite(blueMotorCoil2B, bluePwmSpeed);
      break;
      
    
    case OFF: //off
      //redMotorCoil1 in direction 0
      analogWrite(blueMotorCoil1A, LOW);
      analogWrite(blueMotorCoil1B, LOW);

      //redMotorCoil2 in direction 0
      analogWrite(blueMotorCoil2A, LOW);
      analogWrite(blueMotorCoil2B, LOW);
      break;
      
    default: //off
      //redMotorCoil1 in direction 0
      analogWrite(blueMotorCoil1A, LOW);
      analogWrite(blueMotorCoil1B, LOW);

      //redMotorCoil2 in direction 0
      analogWrite(blueMotorCoil2A, LOW);
      analogWrite(blueMotorCoil2B, LOW);
      break;
  }
}
    
