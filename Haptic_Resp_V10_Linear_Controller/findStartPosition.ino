void findStartPosition (){
  static int speedCounter =0;
  
// code pushes Red motor to one corner, until not reading any change in position (reached boundary), 
// then pushes blue motor to end until not reading any change in position, then press reset on decoder

//RED MOTOR BOUNDS - X

  while(speedCounter < 250){
    setRedMotorSpeed(speedCounter, OUTWARD);
    speedCounter++;
    delay(5);
  }
  /*int pastPosition = redActualPosition;
  Serial.println (pastPosition);
  delay(100);
  int currentPosition = redActualPosition;
  
  Serial.println (currentPosition);
  while ( currentPosition != pastPosition){
    pastPosition=currentPosition;
    delay(200);
    currentPosition = redActualPosition;
  }*/
  delay(500);
  digitalWrite(redResetPin,LOW);
  delay(10);
  digitalWrite(redResetPin,HIGH);
  digitalWrite(redLatchPin, HIGH); 
  setRedMotorSpeed(0, OFF);
  //Serial.println ("FINISHED INITIALIZATION");

//BLUE MOTOR BOUNDS - Y
  speedCounter = 0;
  while(speedCounter < 250){
    setBlueMotorSpeed(speedCounter, OUTWARD);
    speedCounter++;
    delay(5);
  }
  /*setBlueMotorSpeed(200, OUTWARD);
  pastPosition = blueActualPosition;
  delay(300);
  currentPosition = blueActualPosition;
  
  while ( currentPosition != pastPosition){
    pastPosition=currentPosition;
    delay(200);
    currentPosition = blueActualPosition;
  }*/
  delay(500);
  setBlueMotorSpeed(0, OFF);
  digitalWrite(blueResetPin,LOW);
  delay(100);
  digitalWrite(blueResetPin,HIGH);
  digitalWrite(blueLatchPin, HIGH); 
}

