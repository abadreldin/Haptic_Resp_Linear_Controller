#define MAX 256
#define MIN 0

#define redPositionPin7 5 //D7
#define redPositionPin6 6
#define redPositionPin5 7
#define redPositionPin4 8
#define redPositionPin3 9
#define redPositionPin2 10
#define redPositionPin1 11
#define redPositionPin0 12 //D0
#define directionPin 13//ignore
#define redLatchPin A5 //OEN
#define redResetPin A2 //Reset 
#define redSEL1 A1
#define redSEL2 A0

#define bluePositionPin7 5 //D7
#define bluePositionPin6 6
#define bluePositionPin5 7
#define bluePositionPin4 8
#define bluePositionPin3 9
#define bluePositionPin2 10
#define bluePositionPin1 11
#define bluePositionPin0 12 //D0
#define directionPin 13//ignore
#define blueLatchPin A5 //OEN
#define blueResetPin A2 //Reset 
#define blueSEL1 A1
#define blueSEL2 A0

#define pGain 2

#define timerInterrupt 0.000125
#define degToRad 0.01745329251

////////////////////////////////////////////////////////////////////////////////////
typedef enum {
  OFF,
  INWARD,
  OUTWARD
}directions;

directions redMotorDir = OFF;
directions BlueMotorDir = OFF;
////////////////////////////////////////////////////////////////////////////////////

double displacementRed, displacementBlue;
double velocityRed = 0, pastVelocityRed = 0;
double velocityBlue = 0, pastVelocityBlue = 0;
unsigned long startTime;
double redActualPosition, redTimeElapsed, redDesiredPosition, redInitialPosition;
double blueActualPosition, TimeElapsed, desiredPosition, initialPosition;
double acutalPosition;
double xBoundary = 0, yBoundary=0;;
double sum = 0;
int redPwmSpeed = 0;
int bluePwmSpeed = 0;
bool hapticFeedback = 0;

double redTempActualPosition, blueTempActualPosition;
double initPositionRed, initPositionBlue;

/////////////////////////////////////////////////////////////////////////////////////////

void setPwmFrequency(int pin, int divisor);
void setRedMotorSpeed( int redPwmSpeed, directions redMotor);
void setRedMotorSpeed( int bluePwmSpeed, directions blueMotor);
void motorSetup (void);
void timerSetup (void);
void decoderSetup (void);
double computePosition ();
void readSerialCommand();
void findStartPosition();

