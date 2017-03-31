void findStartPosition (){
// code pushes Red motor to one corner, until not reading any change in position (reached boundary), 
// then pushes blue motor to end until not reading any change in position, then press reset on decoder

//RED MOTOR BOUNDS - X

  redPwmSpeed = 100;
  redMotorDir = OUTWARD;
  setRedMotorSpeed(redPwmSpeed, redMotorDir);
  
  delay(200);
  int pastPosition = redActualPosition;
  Serial.println (pastPosition);
  delay(100);
  int currentPosition = redActualPosition;
  
  Serial.println (currentPosition);
  while ( currentPosition != pastPosition){
    pastPosition=currentPosition;
    delay(200);
    currentPosition = redActualPosition;
  }
  delay(500);
  digitalWrite(redResetPin,LOW);
  delay(10);
  digitalWrite(redResetPin,HIGH);
  digitalWrite(redLatchPin, HIGH); 
  setRedMotorSpeed(0, OFF);
  Serial.println ("FINISHED INITIALIZATION");

//BLUE MOTOR BOUNDS - Y
  bluePwmSpeed = 130;
  blueMotorDir = OUTWARD;
  setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
  pastPosition = blueActualPosition;
  delay(200);
  currentPosition = blueActualPosition;
  
  while ( currentPosition != pastPosition){
    pastPosition=currentPosition;
    delay(200);
    currentPosition = blueActualPosition;
  }
  delay(500);
  setBlueMotorSpeed(0, OFF);
  digitalWrite(blueResetPin,LOW);
  delay(100);
  digitalWrite(blueResetPin,HIGH);
  digitalWrite(blueLatchPin, HIGH); 
}

