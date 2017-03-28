#define KI 0.000006041
#define KD 0.005094
#define KP 0.0004342
#define timeInterrupt 10


double computeHapticPath (double actualPosition){
  //static double previousPosition;
  static double s=0;
  static double derivative;
  static double error;

  error = desiredPosition - actualPosition;
  s += error;
  s *= KI;

  s += error*KP;

  derivative = error/timeInterrupt*1000; //assuming the timer is in milliseconds, and I want velocity in rad/s in 

  s += derivative*KD;

  //Serial.println (s);
  return s;  
}

