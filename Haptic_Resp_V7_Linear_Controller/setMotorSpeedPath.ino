void setMotorSpeedPath (){
 // - review how computeVelocity function is set up! on timer interrupts
 //pwmSpeed = velocity*2;
  static double tempPosition;
  tempPosition= actualPosition;
  pwmSpeed = computeHapticPath(tempPosition);
  pwmSpeed = (int) pwmSpeed*18.5185185185/50*3;  
  Serial.println (pwmSpeed);
  //Serial.println (actualPosition);
  analogWrite(pwmPin, pwmSpeed);
  if( pwmSpeed > 0){
  setRedMotorSpeed( pwmSpeed, INWARD);
  }
  else if (pwmSpeed < 0){
    setRedMotorSpeed( abs(pwmSpeed), OUTWARD);
  }
}

