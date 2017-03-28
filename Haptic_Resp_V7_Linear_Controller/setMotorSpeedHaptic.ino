/*void setMotorSpeedHaptic (double velocity){

  pwmSpeed = (int)computeHapticP (velocity);
  
  //Serial.println (pwmSpeed);
  
  if((actualPosition > wall) && (actualPosition < (wall + 35)) && (pwmSpeed < 200)){
      analogWrite(pwmPin, pwmSpeed);
      digitalWrite( HbridgeCCW, HIGH);
      digitalWrite( HbridgeCW, LOW);
      Serial.println (pwmSpeed);
  }
  else if((actualPosition < wall) && (actualPosition > (wall - 35)) && (pwmSpeed < 200)){
      analogWrite(pwmPin, abs(pwmSpeed));
      digitalWrite( HbridgeCCW, LOW);
      digitalWrite( HbridgeCW, HIGH);
      Serial.println (pwmSpeed);
  }
  else
    analogWrite(pwmPin, 0);
  //Serial.println (velocity);
  //Serial.println (actualPosition);
}
*/
