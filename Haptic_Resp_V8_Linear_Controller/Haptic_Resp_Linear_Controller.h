#define MAX 256
#define MIN 0

#define redPositionPin7 36 //D7
#define redPositionPin6 34
#define redPositionPin5 32
#define redPositionPin4 30
#define redPositionPin3 28
#define redPositionPin2 26
#define redPositionPin1 24
#define redPositionPin0 22 //D0
#define directionPin 25//ignore
#define redLatchPin 23 //OEN
#define redResetPin 29 //Reset 
#define redSEL1 33
#define redSEL2 31
#define redTEST 27

#define bluePositionPin7 52 //D7
#define bluePositionPin6 50
#define bluePositionPin5 48
#define bluePositionPin4 46
#define bluePositionPin3 44
#define bluePositionPin2 42
#define bluePositionPin1 40
#define bluePositionPin0 38 //D0
#define directionPin 41//ignore
#define blueLatchPin 39 //OEN
#define blueResetPin 45 //Reset 
#define blueSEL1 49
#define blueSEL2 47
#define blueTEST 43

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
directions blueMotorDir = OFF;
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

