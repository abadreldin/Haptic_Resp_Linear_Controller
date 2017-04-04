#define strengthFactor 30
#define strengthFactorRED 30

int redPwmSpeed = 0;
int bluePwmSpeed = 0;
  
void hapticSystemAction ( actions hapticSystem){

  const static int hardWall = 220;
  //static int redPwmSpeed = 0;
  //static int bluePwmSpeed = 0;
  const static int totalForce = 500;

   static double dx;
   static double dy;
   static double r = 70;
   static double cx = 0;
   static double cy = 0;
   static int tempBlueSpeed;
   static int tempRedSpeed;
   static int desPosBlue;
   static int desPosRed;
   static int hypotenuse;
  
  switch(hapticSystem){
    

    case DIAGONALALLEY:
        static int b_Prepline;
        static double redTempPos;
        static double blueTempPos;
        static double distance;
        //static double tempRedSpeed;
        //static double tempBlueSpeed;
        
      if (blueActualPosition > (82 - redActualPosition)) {
        
        b_Prepline = blueActualPosition - redActualPosition;
        redTempPos = (82 - b_Prepline) / 2;
        blueTempPos = 82 - redTempPos;
        distance = sqrt((redActualPosition - redTempPos)*(redActualPosition - redTempPos)) + ((blueActualPosition - blueTempPos)*(blueActualPosition - blueTempPos));
        
        tempRedSpeed = (int)distance * 1/sqrt(2.0);
        redPwmSpeed = (int) redComputeHapticPath(redActualPosition, tempRedSpeed);
        Serial << redPwmSpeed << "\n";
        redPwmSpeed = (int)(abs(redPwmSpeed));
        redPwmSpeed = (int)(100 + abs(redPwmSpeed)/3); 
        redMotorDir = OUTWARD;
  
        tempBlueSpeed = (int)distance * 1/sqrt(2.0);
        bluePwmSpeed = (int) blueComputeHapticPath(blueActualPosition, tempBlueSpeed);
        Serial << bluePwmSpeed << "\n";
        bluePwmSpeed = (int)(abs(bluePwmSpeed)); 
        bluePwmSpeed = (int)(100 + abs(bluePwmSpeed)/3); 
        blueMotorDir = OUTWARD;      

        if (redPwmSpeed >160)
          setRedMotorSpeed(160, redMotorDir);
        else
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        if (bluePwmSpeed >160)
          setBlueMotorSpeed(160, blueMotorDir);
        else
          setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
       else {
          setBlueMotorSpeed(0, OFF);
          setRedMotorSpeed(0, OFF);
      }
      delay(10);

      if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;



    
    //keeps the user inside of the square
    case INNERSQUARE:

      if ((redActualPosition >= xBoundaryMax)&& (blueActualPosition <= yBoundaryMin)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = /*255;*/strengthFactor*(redActualPosition - xBoundaryMax);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);

            blueMotorDir = INWARD;
            bluePwmSpeed = /*255;*/strengthFactor*(yBoundaryMin - blueActualPosition);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition >= xBoundaryMax)&& (blueActualPosition >= yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = /*255;*/strengthFactor*(redActualPosition - xBoundaryMax);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = OUTWARD;
            bluePwmSpeed = /*255;*/strengthFactor*(blueActualPosition - yBoundaryMax);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= xBoundaryMin)&& (blueActualPosition >= yBoundaryMax)) {
            redMotorDir = INWARD;
            redPwmSpeed = /*255;*/strengthFactor*(xBoundaryMin - redActualPosition);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = OUTWARD;
            bluePwmSpeed = /*255;*/strengthFactor*(blueActualPosition - yBoundaryMax);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= xBoundaryMin)&& (blueActualPosition <= yBoundaryMin)) {
            redMotorDir = INWARD;
            redPwmSpeed = /*255;*/strengthFactor*(xBoundaryMin - redActualPosition);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = INWARD;
            bluePwmSpeed = /*255;*/strengthFactor*(yBoundaryMin - blueActualPosition);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= (xBoundaryMin))&& (redActualPosition <= 40) && (blueActualPosition >= (yBoundaryMin -5)) && (blueActualPosition <= (yBoundaryMax +5))) {
            redMotorDir = INWARD;
            redPwmSpeed = /*255;*/strengthFactorRED*(xBoundaryMin - redActualPosition);
            //redPwmSpeed = 255;
            if (redPwmSpeed > 255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);

            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition >= (xBoundaryMax)) && (redActualPosition >= 40) && (blueActualPosition >= yBoundaryMin) && (blueActualPosition <= yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = /*255;*/strengthFactorRED*(redActualPosition - xBoundaryMax);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((blueActualPosition <= (yBoundaryMin))&& (blueActualPosition <= 40) && (redActualPosition >= xBoundaryMin) && (redActualPosition <= xBoundaryMax)) {
            blueMotorDir = INWARD;
            bluePwmSpeed = /*255;*/strengthFactor*(yBoundaryMin - blueActualPosition);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
             
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else if ((blueActualPosition >= (yBoundaryMax)) && (blueActualPosition >= 40) && (redActualPosition >= xBoundaryMin) && (redActualPosition <= xBoundaryMax)) {
            blueMotorDir = OUTWARD;
            bluePwmSpeed = /*255;*/strengthFactor*(blueActualPosition - yBoundaryMax);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);

            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else {
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
     
      }
      if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;
    
    //pushes the user from the outside of the square back to within the square boundary
    case HARDSQUARE:
      
       if ((redActualPosition >= xBoundaryMax)&& (blueActualPosition <= yBoundaryMin)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = hardWall;//strengthFactor*(redActualPosition - xBoundaryMax);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = INWARD;
            bluePwmSpeed = hardWall;//strengthFactor*(yBoundaryMin - blueActualPosition);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition >= xBoundaryMax)&& (blueActualPosition >= yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = hardWall;//strengthFactor*(redActualPosition - xBoundaryMax);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = OUTWARD;
            bluePwmSpeed = hardWall;//strengthFactor*(blueActualPosition - yBoundaryMax);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= xBoundaryMin)&& (blueActualPosition >= yBoundaryMax)) {
            redMotorDir = INWARD;
            redPwmSpeed = hardWall;//strengthFactor*(xBoundaryMin - redActualPosition);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = OUTWARD;
            bluePwmSpeed = hardWall;//strengthFactor*(blueActualPosition - yBoundaryMax);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= xBoundaryMin)&& (blueActualPosition <= yBoundaryMin)) {
            redMotorDir = INWARD;
            redPwmSpeed = hardWall;//strengthFactor*(xBoundaryMin - redActualPosition);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = INWARD;
            bluePwmSpeed = hardWall;//strengthFactor*(yBoundaryMin - blueActualPosition);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      
      else if ((redActualPosition <= (xBoundaryMin))&& (redActualPosition <= 40) && (blueActualPosition >= (yBoundaryMin)) && (blueActualPosition <= (yBoundaryMax))) {
            redMotorDir = INWARD;
            redPwmSpeed = hardWall;//strengthFactorRED*(xBoundaryMin - redActualPosition);
            //redPwmSpeed = 255;
            if (redPwmSpeed > 255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);

            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition >= (xBoundaryMax)) && (redActualPosition >= 40) && (blueActualPosition >= yBoundaryMin) && (blueActualPosition <= yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = hardWall;//strengthFactorRED*(redActualPosition - xBoundaryMax);
            if (redPwmSpeed >255)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
              
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((blueActualPosition <= (yBoundaryMin))&& (blueActualPosition <= 40) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)) {
            blueMotorDir = INWARD;
            bluePwmSpeed = hardWall;//strengthFactor*(yBoundaryMin - blueActualPosition);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
             
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else if ((blueActualPosition >= (yBoundaryMax)) && (blueActualPosition >= 40) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)) {
            blueMotorDir = OUTWARD;
            bluePwmSpeed = hardWall;//strengthFactor*(blueActualPosition - yBoundaryMax);
            if (bluePwmSpeed >255)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);

            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else {
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
     
      }
      if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;



    
    case SQUARE:
      //////////////// work with edges of square
      if ((redActualPosition > (xBoundaryMin-10))&& (redActualPosition <= (xBoundaryMin)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if((redActualPosition < (xBoundaryMin+10)) &&(redActualPosition > (xBoundaryMin)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)){
            redMotorDir = INWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(redActualPosition - xBoundaryMin));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition > (xBoundaryMax-10)) && (redActualPosition <= (xBoundaryMax)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMax - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if((redActualPosition < (xBoundaryMax+10)) && (redActualPosition > (xBoundaryMax)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)){
            redMotorDir = INWARD;
            redPwmSpeed = 150;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            
      }
      else if ((blueActualPosition > (yBoundaryMin-5)) && (blueActualPosition < (yBoundaryMin)) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)) {
            blueMotorDir = OUTWARD;
            bluePwmSpeed = 200;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else if((blueActualPosition < (yBoundaryMin+5)) && (blueActualPosition > (yBoundaryMin)) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)){
            blueMotorDir = INWARD;
            bluePwmSpeed = 200;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else if ((blueActualPosition > (yBoundaryMax-5))&& (blueActualPosition < (yBoundaryMax)) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)) {
            blueMotorDir = OUTWARD;
            bluePwmSpeed = 200;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else if((blueActualPosition < (yBoundaryMax+5)) && (blueActualPosition >= (yBoundaryMax)) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)){
            blueMotorDir = INWARD;
            bluePwmSpeed = 200;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else {
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
     
      }
      if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;


    
    case CIRCLE:

          dx = redActualPosition;
          dy = blueActualPosition;
          
          if((dx*dx + dy*dy) >= (r*r)){
            
            tempRedSpeed= redActualPosition;
            redPwmSpeed = redComputeHapticPath(tempRedSpeed, 0);
            redPwmSpeed = (int)(50 + abs(redPwmSpeed)/2.42); 
            redMotorDir = OUTWARD;//OUTWARD;

            tempBlueSpeed= blueActualPosition;
            bluePwmSpeed = blueComputeHapticPath(tempBlueSpeed, 0);
            bluePwmSpeed = (int)(50 + abs(bluePwmSpeed)/2.42); 
            blueMotorDir = OUTWARD;//OUTWARD;
            
            if(redPwmSpeed >250)
              setRedMotorSpeed(255, redMotorDir);
            else
              setRedMotorSpeed(redPwmSpeed, redMotorDir);
            if(bluePwmSpeed >250)
              setBlueMotorSpeed(255, blueMotorDir);
            else
              setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
          }
          else{
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
          } 
        
        
        if (micros()%50000 < 333) // if (millis()% 60 <10)
          Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;




    

    
       
    case TRACEBACK:
        delay(1000);
        Serial << "READY TO RECORD";
        for(int pos=199; pos > 0; pos--){
          redDesiredPosition[pos] = redActualPosition;
          blueDesiredPosition[pos] = blueActualPosition;
          delay(50);
          Serial<< redDesiredPosition[pos] << blueDesiredPosition[pos] << "\n";          
          //Serial << redActualPosition <<" " << blueActualPosition << "\n";
        }
        Serial << "RECORDED - PLAYING BACK";
        delay(10);
        for(int pos=0; pos < 199; pos++){
          delay(10);
          Serial<< redDesiredPosition[pos] << blueDesiredPosition[pos] << "\n";
          //Serial << redActualPosition <<" " << blueActualPosition << "\n";
        }
        Serial << "DONEEEEEEEEEEEEEEEEEE";
        blueIndex =0;
        redIndex =0;

     
       while(blueIndex < 199 && redIndex <199){
            if(blueDesiredPosition[blueIndex] < (blueActualPosition + 3)  
           && blueDesiredPosition[blueIndex] > (blueActualPosition - 3) && redDesiredPosition[redIndex] < (redActualPosition + 3)
           && redDesiredPosition[redIndex] > (redActualPosition - 3) ){
              blueIndex++;
              redIndex++;
              SetpointRed = redSetPath[index];
              SetpointBlue= blueSetPath[index];
              myPIDRED.SetMode(AUTOMATIC);
              myPIDBLUE.SetMode(AUTOMATIC);
              setBlueMotorSpeed( 0, OFF);
              setRedMotorSpeed( 0, OFF);
              delay(20);
              Serial << "ONE POINT"<< "\n";
           }
           
          //static double REDtempPosition;
          
          //REDtempPosition= redActualPosition;
          //redPwmSpeed = redComputeHapticPath(REDtempPosition, redSetPath[index]);
          
          /*InputRed = redActualPosition;
          InputBlue = blueActualPosition;
          myPIDRED.Compute();
          myPIDBLUE.Compute();
          Serial << OutputRed << " " << OutputBlue << "\n";
          
          if( (redDesiredPosition[redIndex] - redActualPosition)>0){
            OutputRed = (int)(OutputRed*1.5); 
            if (OutputRed > 255)
              setRedMotorSpeed( 255, INWARD);
            else
              setRedMotorSpeed( OutputRed, INWARD);
          }
          else if( (redDesiredPosition[redIndex] - redActualPosition)<0){
            OutputRed = (int)(OutputRed*1.5 ); 
            if (OutputRed > 255)
              setRedMotorSpeed( 255, OUTWARD);
            else
              setRedMotorSpeed( OutputRed, OUTWARD);
          }
          else if( OutputRed == 0)
            setRedMotorSpeed( 0, OFF);
          else
            setRedMotorSpeed( 0, OFF);
    
          if( (blueDesiredPosition[blueIndex] - blueActualPosition)>0){
            OutputBlue = (int)(OutputBlue*1.5); 
            if (OutputBlue > 255)
              setBlueMotorSpeed( 255, INWARD);
            else
              setBlueMotorSpeed( OutputBlue, INWARD);
          }
          else if( (blueDesiredPosition[blueIndex] - blueActualPosition)<0){
            OutputRed = (int)(OutputBlue*1.5 ); 
            if (OutputBlue > 255)
              setBlueMotorSpeed( 255, OUTWARD);
            else
              setBlueMotorSpeed( OutputBlue, OUTWARD);
          }
          else if( OutputBlue == 0)
            setBlueMotorSpeed( 0, OFF);
          else
            setBlueMotorSpeed( 0, OFF);
    }*/

           else{
            Serial << "HAPTIC" << "\n";
              static double REDtempPosition;


              /*int error = desiredPosition - actualPosition;
              const int minValue = 120;
          
              double currentPWM = (error/40.0)*(255 - minValue);
              static int lastError = 0;
              if(error == lastError){
                Serial << currentPWM << "\n";
                return (int) currentPWM + 1;
              }*/

              
              REDtempPosition= redActualPosition;
              redPwmSpeed = redComputeTracebackPath(REDtempPosition, redDesiredPosition[redIndex]);
              
              if( redPwmSpeed > 0){
                redPwmSpeed = (int)(135 + redPwmSpeed/2.42); 
                if (redPwmSpeed > 255)
                  setRedMotorSpeed( 255, INWARD);
                else
                  setRedMotorSpeed( redPwmSpeed, INWARD);
              }
              else if (redPwmSpeed < 0){
                redPwmSpeed = (int)(135 + abs(redPwmSpeed)/2.42);  
                if (redPwmSpeed > 255)
                  setRedMotorSpeed( 255, OUTWARD);
                else
                  setRedMotorSpeed( redPwmSpeed, OUTWARD);
              }
              else if( redPwmSpeed == 0)
                setRedMotorSpeed( 0, OFF);
              else
                setRedMotorSpeed( 0, OFF);
        
        
            //double computeHapticPath (double actualPosition)
              static double BLUEtempPosition;
              BLUEtempPosition= blueActualPosition;
              bluePwmSpeed = blueComputeTracebackPath(BLUEtempPosition, blueDesiredPosition[redIndex]);        
              
              if( bluePwmSpeed > 0){
                bluePwmSpeed = (int)(135 + bluePwmSpeed/2.42); 
                if (bluePwmSpeed > 255)
                  setBlueMotorSpeed( 255, INWARD);
                else
                  setBlueMotorSpeed( bluePwmSpeed, INWARD);
              }
              else if (bluePwmSpeed < 0){
                bluePwmSpeed = (int)(135 + abs(bluePwmSpeed)/2.42);  
                if (bluePwmSpeed > 255)
                  setBlueMotorSpeed( 255, OUTWARD);
                else
                  setBlueMotorSpeed( bluePwmSpeed, OUTWARD);
              }
              else if( bluePwmSpeed == 0)
                setBlueMotorSpeed( 0, OFF);
              else
                setBlueMotorSpeed( 0, OFF);
            }
            if (micros()%50000 < 333) // if (millis()% 60 <10)
          Serial << redActualPosition <<" " << blueActualPosition << "\n";
  }
       
      break;



      
    /*case PATH:

    static const int PWMredOutput = 120;
    static const int PWMblueOutput = 100;
       
       if(blueSetPath[index] < (blueActualPosition + 2) && blueSetPath[index+1] != "\0" 
       && blueSetPath[index] > (blueActualPosition - 2) && redSetPath[index] < (redActualPosition + 3)
       && redSetPath[index] > (redActualPosition - 3) && redSetPath[index+1] != "\0"){
          //index++;
          SetpointRed = redSetPath[index];
          SetpointBlue= blueSetPath[index];
          myPIDRED.SetMode(AUTOMATIC);
          myPIDBLUE.SetMode(AUTOMATIC);
          setBlueMotorSpeed( 0, OFF);
          setRedMotorSpeed( 0, OFF);
          delay(500);
       }
       else if(blueSetPath[index+1] == "\0" || redSetPath[index+1] == "\0"){
          setBlueMotorSpeed( 0, OFF);
          setRedMotorSpeed( 0, OFF);
          result=99; 
          Serial << "DONE" << "\n";
       }
       else{
          //static double REDtempPosition;
          
          //REDtempPosition= redActualPosition;
          //redPwmSpeed = redComputeHapticPath(REDtempPosition, redSetPath[index]);
          
          InputRed = redActualPosition;
          InputBlue = blueActualPosition;
          myPIDRED.Compute();
          myPIDBLUE.Compute();
          Serial << OutputRed << " " << OutputBlue << "\n";
          
          if( (redSetPath[index] - redActualPosition)>0){
            OutputRed = (int)(OutputRed); 
            if (OutputRed > 255)
              setRedMotorSpeed( 255, INWARD);
            else
              setRedMotorSpeed( OutputRed +100, INWARD);
          }
          else if( (redSetPath[index] - redActualPosition)<0){
            OutputRed = (int)(OutputRed); 
            if (OutputRed > 255)
              setRedMotorSpeed( 255, OUTWARD);
            else
              setRedMotorSpeed( OutputRed + 100, OUTWARD);
          }
          else if( OutputRed == 0)
            setRedMotorSpeed( 0, OFF);
          else
            setRedMotorSpeed( 0, OFF);
    
          if( (blueSetPath[index] - blueActualPosition)>0){
            OutputBlue = (int)(OutputBlue); 
            if (OutputBlue > 255)
              setBlueMotorSpeed( 255, INWARD);
            else
              setBlueMotorSpeed( OutputBlue + 100, INWARD);
          }
          else if( (blueSetPath[index] - blueActualPosition)<0){
            OutputRed = (int)(OutputBlue); 
            if (OutputBlue > 255)
              setBlueMotorSpeed( 255, OUTWARD);
            else
              setBlueMotorSpeed( OutputBlue + 10, OUTWARD);
          }
          else if( OutputBlue == 0)
            setBlueMotorSpeed( 0, OFF);
          else
            setBlueMotorSpeed( 0, OFF);
    }

        //if (micros()%50000 < 333) // if (millis()% 60 <10)
          //Serial << redActualPosition <<" " << blueActualPosition << "\n";
       
      break;*/


       case PATH:
       if(blueSetPath[index] < (blueActualPosition + 4) && blueSetPath[index+1] != "\0" 
       && blueSetPath[index] > (blueActualPosition - 4) && redSetPath[index] < (redActualPosition + 4)
       && redSetPath[index] > (redActualPosition - 4) && redSetPath[index+1] != "\0"){
          index++;
          setBlueMotorSpeed( 0, OFF);
          setRedMotorSpeed( 0, OFF);
          delay(500);
       }
       else if(blueSetPath[index+1] == "\0" || redSetPath[index+1] == "\0"){
          setBlueMotorSpeed( 0, OFF);
          setRedMotorSpeed( 0, OFF);
          result=0; 
          //Serial << "DONE" << "\n";
       }
       else{
          static double REDtempPosition;
          
          REDtempPosition= redActualPosition;
          redPwmSpeed =  redComputeTracebackPath(REDtempPosition, redSetPath[index]);
          
          if( redPwmSpeed > 0){
            redPwmSpeed = (int)(125 + redPwmSpeed/2.42); 
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, INWARD);
            else
              setRedMotorSpeed( redPwmSpeed, INWARD);
          }
          else if (redPwmSpeed < 0){
            redPwmSpeed = (int)(125 + abs(redPwmSpeed)/2.42);  
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, OUTWARD);
            else
              setRedMotorSpeed( redPwmSpeed, OUTWARD);
          }
          else if( redPwmSpeed == 0)
            setRedMotorSpeed( 0, OFF);
          else
            setRedMotorSpeed( 0, OFF);
    
    
        //double computeHapticPath (double actualPosition)
          static double BLUEtempPosition;
          BLUEtempPosition= blueActualPosition;
          bluePwmSpeed =  blueComputeTracebackPath( BLUEtempPosition, blueSetPath[index]);
          //Serial.println (bluePwmSpeed);
          //Serial.println (actualPositionblue);
    
          
          if( bluePwmSpeed > 0){
            bluePwmSpeed = (int)(125 + bluePwmSpeed/2.42); 
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, INWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, INWARD);
          }
          else if (bluePwmSpeed < 0){
            bluePwmSpeed = (int)(125 + abs(bluePwmSpeed)/2.42);  
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, OUTWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, OUTWARD);
          }
          else if( bluePwmSpeed == 0)
            setBlueMotorSpeed( 0, OFF);
          else
            setBlueMotorSpeed( 0, OFF);
        }

        if (micros()%50000 < 333) // if (millis()% 60 <10)
          Serial << redActualPosition <<" " << blueActualPosition << "\n";

               
      break;




      
    /*case WELL:
       static const int basePWMred = 120;
       static const int basePWMblue = 100;
       static double REDtempPosition;
       REDtempPosition= redActualPosition;
       redPwmSpeed = errorAdjust(REDtempPosition, 40);
          
          if( redPwmSpeed > 0){
            setRedMotorSpeed( redPwmSpeed+basePWMred, INWARD);
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, INWARD);
            else
              setRedMotorSpeed( redPwmSpeed, INWARD);
          }
          else if (redPwmSpeed < 0){  
            setRedMotorSpeed( abs(redPwmSpeed+basePWMred), INWARD);
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, OUTWARD);
            else
              setRedMotorSpeed( redPwmSpeed, OUTWARD);
          }
          else if( redPwmSpeed == 0)
            setRedMotorSpeed( 0, OFF);
          else
            setRedMotorSpeed( 0, OFF);
    
    
        //double computeHapticPath (double actualPosition)
          static double BLUEtempPosition;
          BLUEtempPosition= blueActualPosition;
          bluePwmSpeed = blueComputeHapticPath(BLUEtempPosition, 40);
          //Serial << bluePwmSpeed << "\n"; 
          
          if( bluePwmSpeed > 0){
            bluePwmSpeed = (int)(basePWMblue + bluePwmSpeed/2.42);
            
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, INWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, INWARD);
          }
          else if (bluePwmSpeed < 0){
            bluePwmSpeed = (int)(basePWMblue + abs(bluePwmSpeed)/2.42);  
            
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, OUTWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, OUTWARD);
          }
          else if( bluePwmSpeed == 0)
            setBlueMotorSpeed( 0, OFF);
          else
            setBlueMotorSpeed( 0, OFF);
            
        //if (micros()%50000 < 333) // if (millis()% 60 <10)
        //  Serial << redActualPosition <<" " << blueActualPosition << "\n";
      break;
*/

case WELL:
       static double REDtempPosition;
       REDtempPosition= redActualPosition;
       redPwmSpeed = redComputeTracebackPath(REDtempPosition, 40);
          
          if( redPwmSpeed > 0){
            redPwmSpeed = (int)(125 + redPwmSpeed/2.42); 
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, INWARD);
            else
              setRedMotorSpeed( redPwmSpeed, INWARD);
          }
          else if (redPwmSpeed < 0){
            redPwmSpeed = (int)(125 + abs(redPwmSpeed)/2.42);  
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, OUTWARD);
            else
              setRedMotorSpeed( redPwmSpeed, OUTWARD);
          }
          else if( redPwmSpeed == 0)
            setRedMotorSpeed( 0, OFF);
          else
            setRedMotorSpeed( 0, OFF);
    
    
        //double computeHapticPath (double actualPosition)
          static double BLUEtempPosition;
          BLUEtempPosition= blueActualPosition;
          bluePwmSpeed = blueComputeTracebackPath(BLUEtempPosition, 40);
          
          if( bluePwmSpeed > 0){
            bluePwmSpeed = (int)(120 + bluePwmSpeed/2.42); 
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, INWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, INWARD);
          }
          else if (bluePwmSpeed < 0){
            bluePwmSpeed = (int)(120 + abs(bluePwmSpeed)/2.42);  
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, OUTWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, OUTWARD);
          }
          else if( bluePwmSpeed == 0)
            setBlueMotorSpeed( 0, OFF);
          else
            setBlueMotorSpeed( 0, OFF);
        if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
      break;


      
        
    case MOTOROFF:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
        redMotorDir = OFF;
        redPwmSpeed = 0;
        setRedMotorSpeed(redPwmSpeed, redMotorDir);
        //Serial << "motor off" << "\n";
    break;

    
    

    case CORNSTARCHWALL:
      // Wall that is hard if you hit it quickly, but soft if you hit slowly

      //setRedMotorSpeed(200, INWARD);
      static int redTempActualPosition, blueTempActualPosition;
      static int redInitPosition, blueInitPosition;
      const static int wall = 40;
      
      //Calculate current velocity - X DIRECTION
      /*startTime = micros();
      redTempActualPosition = redActualPosition;
      redVelocity = (double)(redTempActualPosition - redInitPosition)/(micros()-startTime)* 1000/12.5;
      
      //Serial.println(redVelocity);
      redInitPosition = redTempActualPosition;*/

      //Calculate current velocity - Y DIRECTION
      startTime = micros();
      blueTempActualPosition = blueActualPosition;
      blueVelocity = (double)(blueTempActualPosition - blueInitPosition)/(micros()-startTime)* 1000/12.5;
      
      //Serial.println(blueVelocity);
      blueInitPosition = blueTempActualPosition;

     
      
      //execute haptic feedback depending on position - WALL and incoming speed

      //very close to wall - increasing velocity
      if((blueActualPosition < (wall + 10)) && (blueActualPosition > (wall - 10)) && (blueVelocity > 0)){
          blueMotorDir = OUTWARD;
          blueVelocity = (blueVelocity*7);
          if(blueVelocity >240){
            setBlueMotorSpeed(255, blueMotorDir);
            delay(30);
          }
      }

      //very close to wall - decreasing velocity
      else if((blueActualPosition < (wall + 10)) && (blueActualPosition > (wall - 10)) && (blueVelocity < 0)){
          blueMotorDir = INWARD;
          blueVelocity = (blueVelocity*7);
          if(blueVelocity >240){
            setBlueMotorSpeed(255, blueMotorDir);
            delay(30);
          }
      }
      
      else if((blueActualPosition < (wall - 10)) && (blueActualPosition > (wall - 35)) && (blueVelocity > 0)){
        blueMotorDir = OUTWARD;
        blueVelocity = (blueVelocity*5);
        if(blueVelocity >240){
          setBlueMotorSpeed(255, blueMotorDir);
          delay(30);
        }
        else if (blueVelocity < 130){
          setBlueMotorSpeed(0, blueMotorDir); 
        }
        else{
          setBlueMotorSpeed(blueVelocity, blueMotorDir);
        //Serial << blueVelocity << "\n";
          delay(30);
        }
      }
      else if((blueActualPosition < (wall - 10)) && (blueActualPosition > (wall - 35)) && (blueVelocity < 0)){
        blueMotorDir = INWARD;
        blueVelocity = abs((blueVelocity*5));
        if(blueVelocity >240){
          setBlueMotorSpeed(255, blueMotorDir);
          delay(30);
        }
        else if (blueVelocity < 130){
          setBlueMotorSpeed(0, blueMotorDir); 
        }
        else{
          setBlueMotorSpeed(blueVelocity, blueMotorDir);
        //Serial << blueVelocity << "\n";
          delay(30);
        }
      }
      else if((blueActualPosition > (wall + 10)) && (blueActualPosition < (wall + 35)) && (blueVelocity < 0)){
        blueMotorDir = INWARD;
        
        blueVelocity = abs((blueVelocity)*5);
        if(blueVelocity >240){
          setBlueMotorSpeed(255, blueMotorDir);
          delay(30);
        }
        else if (blueVelocity < 130){
          setBlueMotorSpeed(0, blueMotorDir); 
        }
        else{
          setBlueMotorSpeed(blueVelocity, blueMotorDir);
          delay(30);
        }
        //Serial << blueVelocity << "\n";
      }
      else if((blueActualPosition > (wall + 10)) && (blueActualPosition < (wall + 35)) && (blueVelocity > 0)){
        blueMotorDir = OUTWARD;
        
        blueVelocity = abs((blueVelocity)*5);
        if(blueVelocity >240){
          setBlueMotorSpeed(255, blueMotorDir);
          delay(30);
        }
        else if (blueVelocity < 130){
          setBlueMotorSpeed(0, blueMotorDir); 
        }
        else{
          setBlueMotorSpeed(blueVelocity, blueMotorDir);
          delay(30);
        }
        //Serial << blueVelocity << "\n";
      }
      else{
        blueMotorDir = OFF;
        setBlueMotorSpeed(0, blueMotorDir);
        redMotorDir = OFF;
        setRedMotorSpeed(0, redMotorDir);
        //Serial <<"0 \n";
      }

      if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";      
    break;



    case BARRIER:
      static const int barrier = 60;
      if(redActualPosition > barrier){
            tempRedSpeed= redActualPosition;
            redPwmSpeed = redComputeHapticPath(tempRedSpeed, 0);
            redPwmSpeed = (int)(140 + abs(redPwmSpeed)/2.42); 
            redMotorDir = OUTWARD;//OUTWARD;

            tempBlueSpeed= blueActualPosition;
            bluePwmSpeed = blueComputeHapticPath(tempBlueSpeed, 40);
            bluePwmSpeed = (int)(120 + abs(bluePwmSpeed)/2.42); 
            if(blueActualPosition > 40)
              blueMotorDir = OUTWARD;
            else if(blueActualPosition < 40)
              blueMotorDir = INWARD;
            else
              blueMotorDir = OFF;

            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else{
          setBlueMotorSpeed(0, OFF);
          setRedMotorSpeed(0, OFF);
        
      }
      if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;



    
    default:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
        //if (micros()%50000 < 333) // if (millis()% 60 <10)
          //Serial << redActualPosition <<" " << blueActualPosition << "\n";

}
}



