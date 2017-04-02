void decoderSetup (void){

  pinMode(redLatchPin, OUTPUT); 
  pinMode(redPositionPin0, INPUT); 
  pinMode(redPositionPin1, INPUT); 
  pinMode(redPositionPin2, INPUT); 
  pinMode(redPositionPin3, INPUT); 
  pinMode(redPositionPin4, INPUT); 
  pinMode(redPositionPin5, INPUT); 
  pinMode(redPositionPin6, INPUT); 
  pinMode(redPositionPin7, INPUT); 
  //pinMode(directionPin, INPUT); 
  pinMode(redSEL1, OUTPUT);
  pinMode(redSEL2, OUTPUT);
  pinMode(redResetPin, OUTPUT);
  
  digitalWrite(redResetPin,LOW);
  delay(100);
  digitalWrite(redResetPin,HIGH);
  digitalWrite(redLatchPin, HIGH);

  pinMode(blueLatchPin, OUTPUT); 
  pinMode(bluePositionPin0, INPUT); 
  pinMode(bluePositionPin1, INPUT); 
  pinMode(bluePositionPin2, INPUT); 
  pinMode(bluePositionPin3, INPUT); 
  pinMode(bluePositionPin4, INPUT); 
  pinMode(bluePositionPin5, INPUT); 
  pinMode(bluePositionPin6, INPUT); 
  pinMode(bluePositionPin7, INPUT); 
  //pinMode(directionPin, INPUT); 
  pinMode(blueSEL1, OUTPUT);
  pinMode(blueSEL2, OUTPUT);
  pinMode(blueResetPin, OUTPUT);
  
  digitalWrite(blueResetPin,LOW);
  delay(100);
  digitalWrite(blueResetPin,HIGH);
  digitalWrite(blueLatchPin, HIGH);
}

