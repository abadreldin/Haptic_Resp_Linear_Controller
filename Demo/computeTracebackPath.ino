// NEED TO CHANGE 
// APPLIES TO BOTH -- NEED TO BE CHANGED TO RED AND BLUE

/*#define KI 1.27217711615332e-11
#define KD 0.0934626171836411
#define KP 2.60336362444743e-06*/
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


