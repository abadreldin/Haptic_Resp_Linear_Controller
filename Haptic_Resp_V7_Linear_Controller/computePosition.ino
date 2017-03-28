volatile unsigned int encoder0Pos = 0;

double computePosition (){
  static int powerToTwo[] = {1, 2, 4, 8, 16, 32, 64, 128};
  static int i=0;
  static int positionArr[10];
  
  encoder0Pos = 0;
  digitalWrite(latchPin, LOW);
  digitalWrite(SEL1, HIGH);
  digitalWrite(SEL2, LOW);
  
  //digitalRead(positionPin0)
  if (digitalRead(positionPin0)==HIGH)
      positionArr[0] = 1;
  else if (digitalRead(positionPin0)==LOW)
      positionArr[0] = 0;
  if (digitalRead(positionPin1)==HIGH)
      positionArr[1] = 1;
  else if (digitalRead(positionPin1)==LOW)
      positionArr[1] = 0;
  if (digitalRead(positionPin2)==HIGH)
      positionArr[2] = 1;
  else if (digitalRead(positionPin2)==LOW)
      positionArr[2] = 0;
  if (digitalRead(positionPin3)==HIGH)
      positionArr[3] = 1;
  else if (digitalRead(positionPin3)==LOW)
      positionArr[3] = 0;
  if (digitalRead(positionPin4)==HIGH)
      positionArr[4] = 1;
  else if (digitalRead(positionPin4)==LOW)
      positionArr[4] = 0;
  if (digitalRead(positionPin5)==HIGH)
      positionArr[5] = 1;
  else if (digitalRead(positionPin5)==LOW)
      positionArr[5] = 0;
  if (digitalRead(positionPin6)==HIGH)
      positionArr[6] = 1;
  else if (digitalRead(positionPin6)==LOW)
      positionArr[6] = 0;
  if (digitalRead(positionPin7)==HIGH)
      positionArr[7] = 1;
  else if (digitalRead(positionPin7)==LOW)
      positionArr[7] = 0;
  /*if (digitalRead(positionPin8)==HIGH)
      positionArr[8] = 1;
  else if (digitalRead(positionPin8)==LOW)
      positionArr[8] = 0;*/
      
      
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
    //encoder0Pos = encoder0Pos + positionArr[i]*pow(2,i);
    if (positionArr[i]==1)
      encoder0Pos = encoder0Pos + powerToTwo[i];
  }
  digitalWrite(latchPin, HIGH);
  return (double) encoder0Pos;
}
