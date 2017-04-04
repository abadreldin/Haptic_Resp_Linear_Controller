void findStartPosition (){
  static int speedCounter =100;
  
// code pushes Red motor to one corner, until not reading any change in position (reached boundary), 
// then pushes blue motor to end until not reading any change in position, then press reset on decoder

//RED MOTOR BOUNDS - X

  while(speedCounter < 220){
    setRedMotorSpeed(speedCounter, OUTWARD);
    speedCounter++;
    delay(3);
  }
  delay(200);
  digitalWrite(redResetPin,LOW);
  delay(10);
  digitalWrite(redResetPin,HIGH);
  digitalWrite(redLatchPin, HIGH); 
  setRedMotorSpeed(0, OFF);

//BLUE MOTOR BOUNDS - Y
  speedCounter = 170;
  while(speedCounter < 255){
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

