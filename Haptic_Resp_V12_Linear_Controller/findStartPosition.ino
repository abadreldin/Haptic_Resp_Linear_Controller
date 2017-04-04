void findStartPosition (){
  static int speedCounter =100;
  
// code pushes Red motor to one corner, until not reading any change in position (reached boundary), 
// then pushes blue motor to end until not reading any change in position, then press reset on decoder

//RED MOTOR BOUNDS - X

  while(speedCounter < 250){
    setRedMotorSpeed(speedCounter, OUTWARD);
    speedCounter++;
    delay(3);
  }
  delay(500);
  digitalWrite(redResetPin,LOW);
  delay(10);
  digitalWrite(redResetPin,HIGH);
  digitalWrite(redLatchPin, HIGH); 
  setRedMotorSpeed(0, OFF);

//BLUE MOTOR BOUNDS - Y
  speedCounter = 100;
  while(speedCounter < 240){
    setBlueMotorSpeed(speedCounter, OUTWARD);
    speedCounter++;
    delay(5);
  }
  delay(500);
  setBlueMotorSpeed(0, OFF);
  digitalWrite(blueResetPin,LOW);
  delay(10);
  digitalWrite(blueResetPin,HIGH);
  digitalWrite(blueLatchPin, HIGH); 
}

