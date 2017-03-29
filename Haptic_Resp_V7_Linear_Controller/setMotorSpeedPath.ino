void setMotorSpeedPath (){
 // - review how computeVelocity function is set up! on timer interrupts
 //pwmSpeed = velocity*2;
  static double tempPosition;
  tempPosition= actualPositionRed;
  pwmSpeedRed = computeHapticPath(tempPosition);
  pwmSpeedRed = (int) pwmSpeedRed*18.5185185185/50*3;  
  Serial.println (pwmSpeedRed);
  //Serial.println (actualPositionRed);
  if( pwmSpeedRed > 0){
  setRedMotorSpeed( pwmSpeedRed, INWARD);
  }
  else if (pwmSpeedRed< 0){
  setRedMotorSpeed( abs(pwmSpeedRed), OUTWARD);
  }
}

