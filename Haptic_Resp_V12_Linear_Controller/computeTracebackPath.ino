
#define KP 9.37743940130349e-07
#define KD 0.0502265934390315
#define KI 1.89945221638356e-12

#define timeInterrupt 10


double redComputeTracebackPath (double actualPosition, int desiredPosition){
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

  return s;  
}

double blueComputeTracebackPath (double actualPosition, int desiredPosition){
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

  return s;  
}


