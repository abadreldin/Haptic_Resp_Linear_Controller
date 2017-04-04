/*#define KI 1.27217711615332e-11
#define KD 0.0934626171836411
#define KP 2.60336362444743e-06*/
#define KP 9.37743940130349e-07
#define KD 0.0502265934390315
#define KI 1.89945221638356e-12

#define timeInterrupt 10

const int sFactor = 1;
int pastErrorX = 0;
int pastErrorY = 0;
static int sRed;

double redComputeHapticPath (int actualPosition, int desiredPosition){
  //static double previousPosition;
  
  static int derivative;
  static int error;
  
  error = desiredPosition - actualPosition;

  sRed += error*sFactor;
  sRed *= KI;
  sRed += error*KP;
  derivative = error/timeInterrupt*1000; //assuming the timer is in milliseconds, and I want velocity in rad/s in 
  sRed += derivative*KD;
  
  return sRed;  
}

int errorAdjust(int actualPosition, int desiredPosition){
    int error = desiredPosition - actualPosition;
    const int minValue = 120;

    double currentPWM = (error/40.0)*(255 - minValue);
    static int lastError = 0;
    if(error == lastError){
      Serial << currentPWM << "\n";
      return (int) currentPWM + 1;
    }
    lastError = error;
    return (int) currentPWM;
}

double blueComputeHapticPath (int actualPosition, int desiredPosition){
  //static double previousPosition;
  static int s=0;
  static int derivative;
  static int error;

  error = desiredPosition - actualPosition;
  s += error;
  s *= KI;
  s += error*KP;
  derivative = error/timeInterrupt*1000; //assuming the timer is in milliseconds, and I want velocity in rad/s in 
  s += derivative*KD*sFactor;

  return s;  
}


