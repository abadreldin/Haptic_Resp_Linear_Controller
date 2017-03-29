
#define pwmPin 10
#define increment 1
#define mulFactor 0.9
#define MAX 400
#define MIN 0
#define arrSize 10
#define radius 1.0

//#define positionPin8 2
#define positionPin7 5 //D7
#define positionPin6 6
#define positionPin5 7
#define positionPin4 8
#define positionPin3 9
#define positionPin2 10
#define positionPin1 11
#define positionPin0 12 //D0
#define directionPin 13//ignore
#define latchPinRed A5 //OEN
#define resetPinRed A2 //Reset 
#define SEL1 A1
#define SEL2 A0

#define redMotorCoil1A A4 //black
#define redMotorCoil1B 2 //white
#define redMotorCoil2A 3 //grey
#define redMotorCoil2B 4 //purple

/*#define blueMotorCoil1A 5
#define blueMotorCoil1B 6
#define blueMotorCoil2A 7
#define blueMotorCoil2B 8
*/


#define pGain 2

#define timerInterrupt 0.000125
#define degToRad 0.01745329251


typedef enum {
  OFF,
  INWARD,
  OUTWARD
}directions;

double displacementRed, displacementBlue;
double velocityRed = 0, pastVelocityRed = 0;
double velocityBlue = 0, pastVelocityBlue = 0;
unsigned long startTime;
double actualPositionRed, timeElapsedRed, desiredPositionRed, initialPositionRed;
double actualPositionBlue, timeElapsed, desiredPosition, initialPosition;
double acutalPosition;
double xBoundary = 0, yBoundary=0;;
double sum = 0;
int pwmSpeedRed = 0;
int pwmSpeedBlue = 0;
bool hapticFeedback = 0;


boolean toggle2 = 0;
double s=0;
double tempActualPositionRed, tempActualPositionBlue;
double initPositionRed, initPositionBlue;

directions redMotorDir = OFF;
directions BlueMotorDir = OFF;

void setPwmFrequency(int pin, int divisor);
void setRedMotorSpeed( int pwmSpeed, directions redMotor);
void setupMotor (void);
double computePosition ();
void readSerialCommand();
void findStartPosition();

