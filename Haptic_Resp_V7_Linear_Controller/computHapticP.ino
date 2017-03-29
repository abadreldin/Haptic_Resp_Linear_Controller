#define KPinit 0
#define FALSE 0
#define TRUE 1

double computeHapticP (double velocity){
  static double previousPosition =0;
  static double error = desiredPositionRed - actualPositionRed;
  static double kP = 1.5;
  static double s = 0;
  bool flagLimit = FALSE;

  //If velocity is over 10.8 rad/s  then determine if pwm is over or less than 200
  flagLimit = (velocity > 10.8) ? TRUE : FALSE;
  s = (flagLimit == TRUE) ? ((velocity-10.8)/0.054 + 200) : (velocity/0.054);

  return s*50;
}

