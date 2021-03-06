

#define MAX 256
#define MIN 0

#define totalblueForce 150;
#define FALSE 0
#define TRUE 1

//decoder mirrors arduino pins
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

//decoder mirrors arduino pins
#define bluePositionPin7 52 //D7
#define bluePositionPin6 50
#define bluePositionPin5 48
#define bluePositionPin4 46
#define bluePositionPin3 44
#define bluePositionPin2 42
#define bluePositionPin1 40
#define bluePositionPin0 38 //D0
#define direct1ionPin 41//ignore
#define blueLatchPin 39 //OEN
#define blueResetPin 45 //Reset 
#define blueSEL1 49
#define blueSEL2 47
#define blueTEST 43

#define pGain 2

#define timerInterrupt 0.000125
#define degToRad 0.01745329251

//test- better config
/*#define blueMotorEn 7 
#define blueMotorCoil1A 11 //black
#define blueMotorCoil1B 10 //white
#define blueMotorCoil2A 9 //grey
#define blueMotorCoil2B 8 //purple*/

//for testing -- works very well
#define redMotorEn 4
#define redMotorCoil1A 2
#define redMotorCoil1B 3
#define redMotorCoil2A 6
#define redMotorCoil2B 5

#include <PID_v1.h>
////////////////////////////////////////////////////////////////////////////////////
typedef enum {
  OFF,
  INWARD,
  OUTWARD
}directions;

directions redMotorDir = OFF;
directions blueMotorDir = OFF;
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
typedef enum {
  SQUARE,
  CIRCLE,
  CORNER,
  TRACEBACK,
  PATH,
  WELL,
  HILL,
  MOTOROFF,
  INNERSQUARE,
  HARDSQUARE,
  BUTTON,
  CORNSTARCHWALL,
  DIAGONAL,
  INCIRCLE,
  PATHTRACE,
  BARRIER,
  DIAGONALALLEY
}actions;

actions hapticSystem =  MOTOROFF;
////////////////////////////////////////////////////////////////////////////////////
int result=0;
int i=0;
char buf[3];
bool finished= FALSE;

double displacementRed, displacementBlue;
double redVelocity = 0, redPastVelocity = 0;
double blueVelocity = 0, bluePastVelocity = 0;
unsigned long startTime;
int redActualPosition, redTimeElapsed;
int redSetPath[] = {40, 10,10, 70, 70, 40};
int blueSetPath[] = {40, 10,70,70,10, 40};
int redInitialPosition;
int blueActualPosition, TimeElapsed, initialPosition;
double acutalPosition;
int xBoundaryMin = 0, yBoundaryMin=0;
int xBoundaryMax = 0, yBoundaryMax=0;
int xBoundaryMin2 = 0, yBoundaryMin2=0;
int xBoundaryMax2 = 0, yBoundaryMax2=0;
double sum = 0;
bool hapticFeedback = 0;

int printCounter =0;
int index =0;
int blueIndex =0;
int redIndex =0;

int path[2][1000];
int redDesiredPosition[1000];
int blueDesiredPosition[1000];
/////////////////////////////////////////////////////////////////////////////////////////

void setRedMotorSpeed( int redPwm, directions redMotor);
void setBlueMotorSpeed( int bluePwm, directions blueMotor);
void motorSetup (void);
void timerSetup (void);
void decoderSetup (void);
double computePositionBlue ();
double computePositionRed ();
void readSerialCommand();
void findStartPosition();
void hapticSystemAction ( actions hapticSystem);
void setMotorSpeedHaptic (double motorVelocity);
void checkPosition (void);

template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }
