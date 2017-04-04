#define strengthFactor 20
#define strengthFactorRED 30
void hapticSystemAction ( actions hapticSystem){

  const static int hardWall = 220;
  static int redPwmSpeed = 0;
  static int bluePwmSpeed = 0;
  const static int totalForce = 500;
  
  switch(hapticSystem){
    
    case DIAGONAL:
      if (blueActualPosition > (-redActualPosition + 82)) {
        redMotorDir = OUTWARD;
        redPwmSpeed = 200;
        blueMotorDir = OUTWARD;
        bluePwmSpeed = 200;
        setRedMotorSpeed(redPwmSpeed, redMotorDir);
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else {
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
    //////////////// work with corners of square
       /*if ((redActualPosition > (xBoundaryMin-10))&& (redActualPosition <= (xBoundaryMin)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 200;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition > (xBoundaryMin-10))&& (redActualPosition <= (xBoundaryMin)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition > (xBoundaryMin-10))&& (redActualPosition <= (xBoundaryMin)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition > (xBoundaryMin-10))&& (redActualPosition <= (xBoundaryMin)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }*/
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


    
    /*case CIRCLE:

        /*Serial.print("please input circle parameters...");
        Serial.print("center x position (0 - 83): ");
        int cx = Serial.read();
        Serial.print("center y position (0-83): ");
        int cy = Serial.read();
        Serial.print("radius(0 - 41): ");
        int r = Serial.read();*/
      
       /*static double dx;
       static double dy;
       static double r = 30;
       static double cx = 40;
       static double cy = 40;
       static double tempBlueSpeed;
       static double tempRedSpeed;*/
        
        //quadrant 4
        /*
         * -----------------
         *           /    r
         *           /   /
         *   2       /  /  1
         *           / /
         * ----------.---------
         *          /
         *    3     /    4
         *          /
         *          /
         * -----------------
         *
        if((redActualPosition > cx) && (blueActualPosition > cy)){
          dx = redActualPosition - cx;
          dy = blueActualPosition - cy;
          if((dx*dx + dy*dy) <= (r*r)){
            blueMotorDir = INWARD;//OUTWARD;
            tempBlueSpeed =  (dx/(dx+dy))*totalForce;
            Serial << tempBlueSpeed << "\n";
            redMotorDir = INWARD;//OUTWARD;
            tempRedSpeed = (dx/(dx+dy))*totalForce;
            
            bluePwmSpeed = (int) tempBlueSpeed;
            redPwmSpeed = (int) tempRedSpeed;
            
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
        }
        //quadrant 2
        else if((redActualPosition <= cx) && (blueActualPosition > cy)){
          dx = cx - redActualPosition;
          dy = blueActualPosition - cy;
          if((dx*dx + dy*dy) <= (r*r)){
            blueMotorDir = INWARD;
            tempBlueSpeed = (dy/(dx + dy))*totalForce;//(dy/dx)*totalblueForce;
            redMotorDir = OUTWARD;
            tempRedSpeed =  (dx/(dx+dy))*totalForce;
            bluePwmSpeed = (int) tempBlueSpeed;
            redPwmSpeed = (int) tempRedSpeed;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
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
        }
        //quarant 3
        else if((redActualPosition <= cx) && (blueActualPosition <= cy)){
          dx = cx - redActualPosition;
          dy = cy - blueActualPosition;
          if((dx*dx + dy*dy) <= (r*r)){
            blueMotorDir = OUTWARD;//INWARD;
            tempBlueSpeed = (dy/(dx + dy))*totalForce;//(dy/dx)*totalblueForce;
            redMotorDir = OUTWARD;//INWARD;
            tempRedSpeed = (dx/(dx+dy))*totalForce;
            bluePwmSpeed = (int) tempBlueSpeed;
            redPwmSpeed = (int) tempRedSpeed;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
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
        }
        //quadrant 4
        else if ((redActualPosition > cx) && (blueActualPosition <= cy)) {
          dx = redActualPosition - cx;
          dy = cy - blueActualPosition;
          if((dx*dx + dy*dy) <= (r*r)){
            blueMotorDir = OUTWARD;
            tempBlueSpeed =  (dy/(dx + dy))*totalForce;//(dy/dx)*totalblueForce;
            redMotorDir = INWARD;
            tempRedSpeed = (dx/(dx+dy))*totalForce;
            bluePwmSpeed = (int) tempBlueSpeed;
            redPwmSpeed = (int) tempRedSpeed;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
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
        }
        if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;*/




    case INCIRCLE:

        /*Serial.print("please input circle parameters...");
        Serial.print("center x position (0 - 83): ");
        int cx = Serial.read();
        Serial.print("center y position (0-83): ");
        int cy = Serial.read();
        Serial.print("radius(0 - 41): ");
        int r = Serial.read();*/
      
       static double dx;
       static double dy;
       static double r = 20;
       static double cx = 40;
       static double cy = 40;
       static int tempBlueSpeed;
       static int tempRedSpeed;
       static int desPosBlue;
       static int desPosRed;
       static int hypotenuse;
        
        //quadrant 4
        /*
         * -----------------
         *           /    r
         *           /   /
         *   2       /  /  1
         *           / /
         * ----------.---------
         *          /
         *    3     /    4
         *          /
         *          /
         * -----------------
         */

         
        if((redActualPosition > cx) && (blueActualPosition > cy)){
          dx = redActualPosition - cx;
          dy = blueActualPosition - cy;
          if((dx*dx + dy*dy) >= (r*r)){
            desPosBlue=dy*r/(dx*dx + dy*dy);
            desPosRed=dx*r/(dx*dx + dy*dy);
            
            tempRedSpeed= redActualPosition;
            redPwmSpeed = redComputeHapticPath(tempRedSpeed, (desPosRed + r));
            redPwmSpeed = (int)(150 + abs(redPwmSpeed)/2.42); 
            redMotorDir = OUTWARD;//OUTWARD;

            tempBlueSpeed= blueActualPosition;
            bluePwmSpeed = blueComputeHapticPath(tempBlueSpeed, (desPosBlue + r));
            bluePwmSpeed = (int)(150 + abs(bluePwmSpeed)/2.42); 
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
        }
        //quadrant 2
        else if((redActualPosition <= cx) && (blueActualPosition > cy)){
          dx = cx - redActualPosition;
          dy = blueActualPosition - cy;
          if((dx*dx + dy*dy) >= (r*r)){

            desPosBlue=dy*r/(dx*dx + dy*dy);
            desPosRed=dx*r/(dx*dx + dy*dy);
            
            tempRedSpeed= redActualPosition;
            redPwmSpeed = redComputeHapticPath(tempRedSpeed, desPosRed);
            redPwmSpeed = (int)(150 + redPwmSpeed/2.42); 
            redMotorDir = INWARD;//OUTWARD;

            tempBlueSpeed= blueActualPosition;
            bluePwmSpeed = blueComputeHapticPath(tempBlueSpeed, (desPosBlue + r));
            bluePwmSpeed = (int)(150 + bluePwmSpeed/2.42); 
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
        }
        //quarant 3
        else if((redActualPosition <= cx) && (blueActualPosition <= cy)){
          dx = cx - redActualPosition;
          dy = cy - blueActualPosition;
          if((dx*dx + dy*dy) >= (r*r)){

            desPosBlue=dy*r/(dx*dx + dy*dy);
            desPosRed=dx*r/(dx*dx + dy*dy);

            tempRedSpeed= redActualPosition;
            redPwmSpeed = redComputeHapticPath(tempRedSpeed, desPosRed);
            redPwmSpeed = (int)(150 + redPwmSpeed/2.42); 
            redMotorDir = INWARD;//OUTWARD;

            tempBlueSpeed= blueActualPosition;
            bluePwmSpeed = blueComputeHapticPath(tempBlueSpeed, desPosBlue);
            bluePwmSpeed = (int)(150 + bluePwmSpeed/2.42); 
            blueMotorDir = INWARD;//OUTWARD;
            
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
        }
        //quadrant 4
        else if ((redActualPosition > cx) && (blueActualPosition <= cy)) {
          dx = redActualPosition - cx;
          dy = cy - blueActualPosition;
          if((dx*dx + dy*dy) >= (r*r)){

            desPosBlue=dy*r/(dx*dx + dy*dy);
            desPosRed=dx*r/(dx*dx + dy*dy);
            
            tempRedSpeed= redActualPosition;
            redPwmSpeed = redComputeHapticPath(tempRedSpeed, (desPosRed + r));
            redPwmSpeed = (int)(150 + redPwmSpeed/2.42); 
            redMotorDir = OUTWARD;//OUTWARD;

            tempBlueSpeed= blueActualPosition;
            bluePwmSpeed = blueComputeHapticPath(tempBlueSpeed, desPosBlue);
            bluePwmSpeed = (int)(150 + bluePwmSpeed/2.42); 
            blueMotorDir = INWARD;//OUTWARD;
     
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
        }
        if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;




    
    case CORNER:
      //Haptic Interface - vibration
      if (redActualPosition >= xBoundaryMin) {
        redMotorDir = INWARD;
        redPwmSpeed = 100;
        setRedMotorSpeed(redPwmSpeed, redMotorDir);
        delay(10);
        redMotorDir = OUTWARD;
        redPwmSpeed = 200;
        setRedMotorSpeed(redPwmSpeed, redMotorDir);
        delay(30);
      }
      else {
        redMotorDir = OFF;
        redPwmSpeed = 0;
        setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      if (blueActualPosition >= yBoundaryMin) {
        blueMotorDir = INWARD;
        bluePwmSpeed = 100;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
        delay(10);
        blueMotorDir = OUTWARD;
        bluePwmSpeed = 200;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
        delay(30);
      }
      else {
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;



    
    case TRACEBACK:
    delay(1000);
        for(int pos=99; pos > 0; pos--){
          redDesiredPosition[pos] = redActualPosition;
          blueDesiredPosition[pos] = blueActualPosition;
          delay(50);
          Serial<< redDesiredPosition[pos] << blueDesiredPosition[pos] << "\n";
        }
        Serial << "RECORDED - PLAYING BACK";
        delay(10);
        for(int pos=0; pos < 100; pos++){
          delay(10);
          Serial<< redDesiredPosition[pos] << blueDesiredPosition[pos] << "\n";
        }
        Serial << "DONEEEEEEEEEEEEEEEEEE";
        blueIndex =0;
        redIndex =0;

     
       while(blueIndex < 100 && redIndex <100){
            if(blueDesiredPosition[blueIndex] < (blueActualPosition + 3)  
           && blueDesiredPosition[blueIndex] > (blueActualPosition - 3) && redDesiredPosition[redIndex] < (redActualPosition + 3)
           && redDesiredPosition[redIndex] > (redActualPosition - 3) ){
              blueIndex++;
              redIndex++;
              setBlueMotorSpeed( 0, OFF);
              setRedMotorSpeed( 0, OFF);
              delay(20);
              Serial << "ONE POINT"<< "\n";
           }
           /*else if(blueDesiredPosition[index+1] == "\0" && redDesiredPosition[index+1] == "\0"){
              setBlueMotorSpeed( 0, OFF);
              setRedMotorSpeed( 0, OFF);
           }*/
           else{
            Serial << "HAPTIC" << "\n";
              static double REDtempPosition;
              
              REDtempPosition= redActualPosition;
              redPwmSpeed = redComputeTracebackPath(REDtempPosition, redDesiredPosition[redIndex]);
              
              if( redPwmSpeed > 0){
                redPwmSpeed = (int)(120 + redPwmSpeed/2.42); 
                if (redPwmSpeed > 255)
                  setRedMotorSpeed( 255, INWARD);
                else
                  setRedMotorSpeed( redPwmSpeed, INWARD);
              }
              else if (redPwmSpeed < 0){
                redPwmSpeed = (int)(120 + abs(redPwmSpeed)/2.42);  
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
              //Serial.println (bluePwmSpeed);
              //Serial.println (actualPositionblue);
        
              
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
            }
  }
  if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
      break;



      
    case PATH:
       if(blueSetPath[index] < (blueActualPosition + 2) && blueSetPath[index+1] != "\0" 
       && blueSetPath[index] > (blueActualPosition - 2) && redSetPath[index] < (redActualPosition + 2)
       && redSetPath[index] > (redActualPosition - 2) && redSetPath[index+1] != "\0"){
          index++;
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
          static double REDtempPosition;
          
          REDtempPosition= redActualPosition;
          redPwmSpeed = redComputeHapticPath(REDtempPosition, redSetPath[index]);
          
          if( redPwmSpeed > 0){
            redPwmSpeed = (int)(115 + redPwmSpeed/2.42); 
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, INWARD);
            else
              setRedMotorSpeed( redPwmSpeed, INWARD);
          }
          else if (redPwmSpeed < 0){
            redPwmSpeed = (int)(115 + abs(redPwmSpeed)/2.42);  
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
          bluePwmSpeed = blueComputeHapticPath(BLUEtempPosition, blueSetPath[index]);
          //Serial.println (bluePwmSpeed);
          //Serial.println (actualPositionblue);
    
          
          if( bluePwmSpeed > 0){
            bluePwmSpeed = (int)(110 + bluePwmSpeed/2.42); 
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, INWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, INWARD);
          }
          else if (bluePwmSpeed < 0){
            bluePwmSpeed = (int)(110 + abs(bluePwmSpeed)/2.42);  
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




      
    case WELL:
       static double REDtempPosition;
       REDtempPosition= redActualPosition;
       redPwmSpeed = redComputeHapticPath(REDtempPosition, 40);
          
          if( redPwmSpeed > 0){
            redPwmSpeed = (int)(110 + redPwmSpeed/2.42); 
            if (redPwmSpeed > 255)
              setRedMotorSpeed( 255, INWARD);
            else
              setRedMotorSpeed( redPwmSpeed, INWARD);
          }
          else if (redPwmSpeed < 0){
            redPwmSpeed = (int)(110 + abs(redPwmSpeed)/2.42);  
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
          
          if( bluePwmSpeed > 0){
            bluePwmSpeed = (int)(110 + bluePwmSpeed/2.42); 
            if (bluePwmSpeed > 255)
              setBlueMotorSpeed( 255, INWARD);
            else
              setBlueMotorSpeed( bluePwmSpeed, INWARD);
          }
          else if (bluePwmSpeed < 0){
            bluePwmSpeed = (int)(110 + abs(bluePwmSpeed)/2.42);  
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



      
    case HILL:
    //the larger the position (closer to the edge of the mechanism, the harder you want to roll down the hill) - in the x direction
        if (redActualPosition < 39){
          redMotorDir = OUTWARD;
          redPwmSpeed = redActualPosition*(170/40);
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        }
        else if(redActualPosition > 43){
          redMotorDir = INWARD;
          redPwmSpeed = (85 -redActualPosition)*(170/40);
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        }
        else{
          redMotorDir = OFF;
          redPwmSpeed = 0;
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        }
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
        if (micros()%50000 < 333) // if (millis()% 60 <10)
          Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;

    
    case BUTTON:
        if (redActualPosition < 40){
          redMotorDir = OFF;
          redPwmSpeed = 0;
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        }
        else if(redActualPosition > 50 && redActualPosition <52){
          redMotorDir = OUTWARD;
          redPwmSpeed = 250;
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        }
        else if(redActualPosition <= 50 && redActualPosition > 48){
          redMotorDir = OFF;
          redPwmSpeed = 0;
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        }
        else{
          redMotorDir = OUTWARD;
          redPwmSpeed = (50 - redActualPosition)*(170/10);
          setRedMotorSpeed(redPwmSpeed, redMotorDir);
        }
        if (micros()%50000 < 333) // if (millis()% 60 <10)
        Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;
    
    //case MOVING WALL:
    //break;

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

     //execute haptic just reverse current direction
     /*if(redVelocity >= 0){
        redMotorDir = OUTWARD;
        redVelocity = (redVelocity);
        if(redVelocity >200)
          setRedMotorSpeed(200, redMotorDir);
        else
          setRedMotorSpeed(redVelocity, redMotorDir);
       delay(30);
     }
     else if(redVelocity < 0){
      redMotorDir = INWARD;
      redVelocity = (redVelocity);
      if(redVelocity >200)
        setRedMotorSpeed(200, redMotorDir);
      else
        setRedMotorSpeed(redVelocity, redMotorDir);
      delay(30);
     }*/

      
     /* //execute haptic feedback depending on position - WALL and incoming speed
      if((redActualPosition < (wall + 5)) && (redActualPosition > (wall - 35)) && (redVelocity > 0)){
        redMotorDir = OUTWARD;
        redVelocity = (redVelocity*5);
        if(redVelocity >230){
          setRedMotorSpeed(255, redMotorDir);
          delay(60);
        }
        else if (redVelocity < 130){
          setRedMotorSpeed(0, redMotorDir); 
        }
        else{
          setRedMotorSpeed(redVelocity, redMotorDir);
        //Serial << redVelocity << "\n";
          delay(30);
        }
      }
      else if((redActualPosition > (wall - 5)) && (redActualPosition < (wall + 35)) && (redVelocity < 0)){
        redMotorDir = INWARD;
        
        redVelocity = abs((redVelocity)*5);
        if(redVelocity >230){
          setRedMotorSpeed(255, redMotorDir);
          delay(60);
        }
        else if (redVelocity < 130){
          setRedMotorSpeed(0, redMotorDir); 
        }
        else{
          setRedMotorSpeed(redVelocity, redMotorDir);
          delay(30);
        }
        //Serial << redVelocity << "\n";
      }
      else{
        blueMotorDir = OFF;
        setBlueMotorSpeed(0, blueMotorDir);
        redMotorDir = OFF;
        setRedMotorSpeed(0, redMotorDir);
        //Serial <<"0 \n";
      }*/

      
      //execute haptic feedback depending on position - WALL and incoming speed

      //very close to wall - increasing velocity
      if((blueActualPosition < (wall + 10)) && (blueActualPosition > (wall - 10)) && (blueVelocity > 0)){
          blueMotorDir = OUTWARD;
          blueVelocity = (blueVelocity*7);
          if(blueVelocity >230){
            setBlueMotorSpeed(255, blueMotorDir);
            delay(50);
          }
      }

      //very close to wall - decreasing velocity
      else if((blueActualPosition < (wall + 10)) && (blueActualPosition > (wall - 10)) && (blueVelocity < 0)){
          blueMotorDir = INWARD;
          blueVelocity = (blueVelocity*7);
          if(blueVelocity >230){
            setBlueMotorSpeed(255, blueMotorDir);
            delay(50);
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
            redPwmSpeed = (int)(150 + abs(redPwmSpeed)/2.42); 
            redMotorDir = OUTWARD;//OUTWARD;

            tempBlueSpeed= blueActualPosition;
            bluePwmSpeed = blueComputeHapticPath(tempBlueSpeed, 40);
            bluePwmSpeed = (int)(150 + abs(bluePwmSpeed)/2.42); 
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
        if (micros()%50000 < 333) // if (millis()% 60 <10)
          Serial << redActualPosition <<" " << blueActualPosition << "\n";

}
}



