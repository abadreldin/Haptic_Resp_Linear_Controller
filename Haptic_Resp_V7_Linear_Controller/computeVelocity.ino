#define timerInterrupt 0.000125
#define degToRad 0.01745329251

//measure velocity
double computeVelocity (void){ 
  static double initialPosition;
  static double tempActualPosition = actualPosition;
  velocity = (abs(tempActualPosition - initialPosition))/timerInterrupt * degToRad;
  return velocity;
}
