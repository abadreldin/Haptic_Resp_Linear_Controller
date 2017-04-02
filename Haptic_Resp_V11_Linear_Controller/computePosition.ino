double computePositionRed (){
  static volatile unsigned int redEncoderPos = 0;
  const static int powerToTwo[] = {1, 2, 4, 8, 16, 32, 64, 128};
  static int i=0;
  static int positionArr[8];
  
  redEncoderPos = 0;
  digitalWrite(redLatchPin, LOW);
  digitalWrite(redSEL1, HIGH);
  digitalWrite(redSEL2, LOW);
  
  //digitalRead(positionPin0)
  if (digitalRead(redPositionPin0)==HIGH)
      positionArr[0] = 1;
  else if (digitalRead(redPositionPin0)==LOW)
      positionArr[0] = 0;
  if (digitalRead(redPositionPin1)==HIGH)
      positionArr[1] = 1;
  else if (digitalRead(redPositionPin1)==LOW)
      positionArr[1] = 0;
  if (digitalRead(redPositionPin2)==HIGH)
      positionArr[2] = 1;
  else if (digitalRead(redPositionPin2)==LOW)
      positionArr[2] = 0;
  if (digitalRead(redPositionPin3)==HIGH)
      positionArr[3] = 1;
  else if (digitalRead(redPositionPin3)==LOW)
      positionArr[3] = 0;
  if (digitalRead(redPositionPin4)==HIGH)
      positionArr[4] = 1;
  else if (digitalRead(redPositionPin4)==LOW)
      positionArr[4] = 0;
  if (digitalRead(redPositionPin5)==HIGH)
      positionArr[5] = 1;
  else if (digitalRead(redPositionPin5)==LOW)
      positionArr[5] = 0;
  if (digitalRead(redPositionPin6)==HIGH)
      positionArr[6] = 1;
  else if (digitalRead(redPositionPin6)==LOW)
      positionArr[6] = 0;
  if (digitalRead(redPositionPin7)==HIGH)
      positionArr[7] = 1;
  else if (digitalRead(redPositionPin7)==LOW)
      positionArr[7] = 0;
       
  //FOR DEBUGGING PURPOSES      
  /*Serial.println (positionArr[8]);
  Serial.println (positionArr[7]);
  Serial.println (positionArr[6]);
  Serial.println (positionArr[5]);
  Serial.println (positionArr[4]);
  Serial.println (positionArr[3]);
  Serial.println (positionArr[2]);
  Serial.println (positionArr[1]);
  Serial.println (positionArr[0]);*/
  //Serial.println (desiredPosition);

  for(i=7; i>=0; i--){
    if (positionArr[i]==1)
      redEncoderPos = redEncoderPos + powerToTwo[i];
  }
  digitalWrite(redLatchPin, HIGH);
  return redEncoderPos;
}

double computePositionBlue (){
  static volatile unsigned int blueEncoderPos = 0;
  const static int powerToTwo[] = {1, 2, 4, 8, 16, 32, 64, 128};
  static int i=0;
  static int positionArr[8];
  
  blueEncoderPos = 0;
  digitalWrite(blueLatchPin, LOW);
  digitalWrite(blueSEL1, HIGH);
  digitalWrite(blueSEL2, LOW);
  
  //digitalRead(positionPin0)
  if (digitalRead(bluePositionPin0)==HIGH)
      positionArr[0] = 1;
  else if (digitalRead(bluePositionPin0)==LOW)
      positionArr[0] = 0;
  if (digitalRead(bluePositionPin1)==HIGH)
      positionArr[1] = 1;
  else if (digitalRead(bluePositionPin1)==LOW)
      positionArr[1] = 0;
  if (digitalRead(bluePositionPin2)==HIGH)
      positionArr[2] = 1;
  else if (digitalRead(bluePositionPin2)==LOW)
      positionArr[2] = 0;
  if (digitalRead(bluePositionPin3)==HIGH)
      positionArr[3] = 1;
  else if (digitalRead(bluePositionPin3)==LOW)
      positionArr[3] = 0;
  if (digitalRead(bluePositionPin4)==HIGH)
      positionArr[4] = 1;
  else if (digitalRead(bluePositionPin4)==LOW)
      positionArr[4] = 0;
  if (digitalRead(bluePositionPin5)==HIGH)
      positionArr[5] = 1;
  else if (digitalRead(bluePositionPin5)==LOW)
      positionArr[5] = 0;
  if (digitalRead(bluePositionPin6)==HIGH)
      positionArr[6] = 1;
  else if (digitalRead(bluePositionPin6)==LOW)
      positionArr[6] = 0;
  if (digitalRead(bluePositionPin7)==HIGH)
      positionArr[7] = 1;
  else if (digitalRead(bluePositionPin7)==LOW)
      positionArr[7] = 0;
       
  //FOR DEBUGGING PURPOSES      
  /*Serial.println (positionArr[8]);
  Serial.println (positionArr[7]);
  Serial.println (positionArr[6]);
  Serial.println (positionArr[5]);
  Serial.println (positionArr[4]);
  Serial.println (positionArr[3]);
  Serial.println (positionArr[2]);
  Serial.println (positionArr[1]);
  Serial.println (positionArr[0]);*/
  //Serial.println (desiredPosition);

  for(i=7; i>=0; i--){
    if (positionArr[i]==1)
      blueEncoderPos = blueEncoderPos + powerToTwo[i];
  }
  digitalWrite(blueLatchPin, HIGH);
  return blueEncoderPos;
}
