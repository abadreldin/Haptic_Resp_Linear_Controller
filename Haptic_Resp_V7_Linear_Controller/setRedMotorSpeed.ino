
//blue inward is outward -- reversed from red 



int a = 0;
int b = 0;
int direction_delay = 50;
int f = 3;
int delay_val = 150;
int flag = 0;
//directions redMotor = OFF;
directions blueMotorDir = OFF;

void setupMotor() {

  pinMode(redMotorCoil1A, OUTPUT);
  pinMode(redMotorCoil1B, OUTPUT);
  pinMode(redMotorCoil2A, OUTPUT);
  pinMode(redMotorCoil2A, OUTPUT);

 /* pinMode(blueMotorCoil1A, OUTPUT);
  pinMode(blueMotorCoil1B, OUTPUT);
  pinMode(blueMotorCoil2A, OUTPUT);
  pinMode(blueMotorCoil2A, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);*/
}

//0= off 
//inward - redMotorCoil1 in direction 2 and redMotorCoil2 in direction 1
//outward - redMotorCoil1 in direction 1 and redMotorCoil2 in direction 1
//where direction 0 = off, direction 1: pinA=HIGH, pinB= LOW, and direction 2: pinA=LOW and pinB=HIGH
//where coil 1 refers to pins redMotorCoil1A 1, and redMotorCoil1B and coil 2 refers to redMotorCoil2A 1, and redMotorCoil2B

void setRedMotorSpeed( int pwmSpeed, directions redMotorDir){
  
  switch(redMotorDir){
    case INWARD:
      //redMotorCoil1 in direction 1
      analogWrite(redMotorCoil1A, pwmSpeed);
      analogWrite(redMotorCoil1B, LOW);

      //redMotorCoil2 in direction 2
      analogWrite(redMotorCoil2A, LOW);
      analogWrite(redMotorCoil2B, pwmSpeed);
      break;
      
    case OUTWARD:
      //redMotorCoil1 in direction 2
      analogWrite(redMotorCoil1A, LOW);
      analogWrite(redMotorCoil1B, pwmSpeed);

      //redMotorCoil2 in direction 1
      analogWrite(redMotorCoil2A, pwmSpeed);
      analogWrite(redMotorCoil2B, LOW);
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
    
