///NEED TO CHANGE

void redSetMotorSpeedPath (){
 // - review how computeVelocity function is set up! on timer interrupts
 //pwmSpeed = velocity*2;
  static double tempPosition;
  tempPosition= redActualPosition;
  redPwmSpeed = computeHapticPath(tempPosition);
  redPwmSpeed = (int) redPwmSpeed*18.5185185185/50*3;  
  Serial.println (redPwmSpeed);
  //Serial.println (actualPositionRed);
  if( redPwmSpeed > 0){
  setRedMotorSpeed( redPwmSpeed, INWARD);
  }
  else if (redPwmSpeed< 0){
  setRedMotorSpeed( abs(redPwmSpeed), OUTWARD);
  }
}

