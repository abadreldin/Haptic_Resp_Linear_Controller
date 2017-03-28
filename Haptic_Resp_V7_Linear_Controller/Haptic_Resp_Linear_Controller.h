
#define pwmPin 10
#define increment 1
#define mulFactor 0.9
#define MAX 400
#define MIN 0
#define arrSize 10
#define radius 1.0

//#define positionPin8 2
#define positionPin7 A3 //D7
#define positionPin6 A4
#define positionPin5 5
#define positionPin4 6
#define positionPin3 7
#define positionPin2 8
#define positionPin1 9
#define positionPin0 11 //D0
#define directionPin 13//ignore
#define latchPin A5 //OEN
#define resetPin A2 //Reset 
#define SEL1 A1
#define SEL2 A0


#define pGain 2

#define timerInterrupt 0.000125
#define degToRad 0.01745329251


typedef enum {
  OFF,
  INWARD,
  OUTWARD
}directions;


double angle = 0;
double displacement;
double velocity = 0, pastVelocity = 0;
unsigned long startTime;
double actualPosition, timeElapsed, desiredPosition, initialPosition;
double wall = 0;
double sum = 0;
int pwmSpeed = 127;
bool hapticFeedback = 0;


boolean toggle2 = 0;
double s=0;
double tempActualPosition;
double initPosition;
directions redMotorDir = OFF;


