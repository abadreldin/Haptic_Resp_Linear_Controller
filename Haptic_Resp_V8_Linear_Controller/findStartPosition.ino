void findStartPosition (){
// code pushes Red motor to one corner, until not reading any change in position (reached boundary), 
// then pushes blue motor to end until not reading any change in position, then press reset on decoder

//RED MOTOR BOUNDS - X
  setRedMotorSpeed(230, OUTWARD);
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
  setRedMotorSpeed(0, OFF);
  digitalWrite(redResetPin,LOW);
  delay(100);
  digitalWrite(redResetPin,HIGH);
  digitalWrite(redLatchPin, HIGH); 
  Serial.println ("FINISHED INITIALIZATION");
/*
//BLUE MOTOR BOUNDS - Y
  setBlueMotorSpeed(100, INWARD)
  pastPosition = blueActualPosition;
  delay(100);
  currentPosition = blueActualPosition;
  
  while ( currentPosition != pastPosition){
    pastPosition=currentPosition;
    delay(100);
    currentPosition = blueActualPosition;
  }
  
  setBlueMotorSpeed(0, OFF)
  digitalWrite(blueResetPin,LOW);
  delay(100);
  digitalWrite(blueResetPin,HIGH);
  digitalWrite(blueLatchPin, HIGH); */
}

