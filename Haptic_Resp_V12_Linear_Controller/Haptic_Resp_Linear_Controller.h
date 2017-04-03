#define MAX 256
#define MIN 0
#define totalForce 150;
#define totalblueForce 150;

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

//decoder translates to arduino pins (same designation)
/*#define redPositionPin7 37 //D7
#define redPositionPin6 35
#define redPositionPin5 33
#define redPositionPin4 31
#define redPositionPin3 29
#define redPositionPin2 27
#define redPositionPin1 25
#define redPositionPin0 23 //D0
#define directionPin 24//ignore
#define redLatchPin 22 //OEN
#define redResetPin 28 //Reset 
#define redSEL1 32
#define redSEL2 30
#define redTEST 26*/

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

//decoder translates to arduino pins (same designation)
/*#define bluePositionPin7 53 //D7
#define bluePositionPin6 51
#define bluePositionPin5 49
#define bluePositionPin4 47
#define bluePositionPin3 45
#define bluePositionPin2 43
#define bluePositionPin1 41
#define bluePositionPin0 39 //D0
#define directionPin 40//ignore
#define blueLatchPin 38 //OEN
#define blueResetPin 44 //Reset 
#define blueSEL1 48
#define blueSEL2 46
#define blueTEST 42*/

#define pGain 2

#define timerInterrupt 0.000125
#define degToRad 0.01745329251


#define blueMotorEn 7 
#define blueMotorCoil1A 9 //black
#define blueMotorCoil1B 8 //white
#define blueMotorCoil2A 11 //grey
#define blueMotorCoil2B 10 //purple

#define redMotorEn 2
#define redMotorCoil1A 6
#define redMotorCoil1B 5
#define redMotorCoil2A 4
#define redMotorCoil2B 3

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
  OUTERSQUARE,
  BUTTON,
  CORNSTARCHWALL,
  DIAGONAL
}actions;

actions hapticSystem =  MOTOROFF;
////////////////////////////////////////////////////////////////////////////////////

int i=0;
char buf[3];


double displacementRed, displacementBlue;
double redVelocity = 0, redPastVelocity = 0;
double blueVelocity = 0, bluePastVelocity = 0;
unsigned long startTime;
int redActualPosition, redTimeElapsed;
int redDesiredPosition[] = {20,70, 60, 25};
int blueDesiredPosition[] = {20,30, 60,70};
int redInitialPosition;
int blueActualPosition, TimeElapsed, initialPosition;
double acutalPosition;
int xBoundaryMin = 0, yBoundaryMin=0;
int xBoundaryMax = 0, yBoundaryMax=0;
double sum = 0;
bool hapticFeedback = 0;

int printCounter =0;

/////////////////////////////////////////////////////////////////////////////////////////

void setPwmFrequency(int pin, int divisor);
void setRedMotorSpeed( int redPwmSpeed, directions redMotor);
void setBlueMotorSpeed( int bluePwmSpeed, directions blueMotor);
void motorSetup (void);
void timerSetup (void);
void decoderSetup (void);
double computePosition ();
void readSerialCommand();
void findStartPosition();
void hapticSystemAction ( actions hapticSystem);
void setMotorSpeedHaptic (double motorVelocity);
void checkPosition (void);

template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }
