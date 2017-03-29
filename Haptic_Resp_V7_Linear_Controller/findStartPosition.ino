void findStartPosition (){
// code pushes Red motor to one corner, until not reading any change in position (reached boundary), 
// then pushes blue motor to end until not reading any change in position, then press reset on decoder

//RED MOTOR BOUNDS - X
  setRedMotorSpeed(230, OUTWARD);
  delay(200);
  int pastPosition = actualPositionRed;
  Serial.println (pastPosition);
  delay(100);
  int currentPosition = actualPositionRed;
  
  Serial.println (currentPosition);
  while ( currentPosition != pastPosition){
    pastPosition=currentPosition;
    delay(200);
    currentPosition = actualPositionRed;
  }
  setRedMotorSpeed(0, OFF);
  digitalWrite(resetPinRed,LOW);
  delay(100);
  digitalWrite(resetPinRed,HIGH);
  digitalWrite(latchPinRed, HIGH); 
  Serial.println ("FINISHED INITIALIZATION");
/*
//BLUE MOTOR BOUNDS - Y
  setBlueMotorSpeed(100, INWARD)
  pastPosition = actualPositionBlue;
  delay(100);
  currentPosition = actualPositionBlue;
  
  while ( currentPosition != pastPosition){
    pastPosition=currentPosition;
    delay(100);
    currentPosition = actualPositionBlue;
  }
  
  setBlueMotorSpeed(0, OFF)
  digitalWrite(resetPinBlue,LOW);
  delay(100);
  digitalWrite(resetPinBlue,HIGH);
  digitalWrite(latchPinBlue, HIGH); */
}

