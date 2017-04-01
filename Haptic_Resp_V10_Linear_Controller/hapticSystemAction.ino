void hapticSystemAction ( actions hapticSystem){

  static int redPwmSpeed = 0;
  static int bluePwmSpeed = 0;
  
  switch(hapticSystem){
    //keeps the user inside of the square
    case INNERSQUARE:

      if ((redActualPosition >= xBoundaryMax)&& (blueActualPosition <= yBoundaryMin)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 100;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = INWARD;
            bluePwmSpeed = 100;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition >= xBoundaryMax)&& (blueActualPosition >= yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 100;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OUTWARD;
            bluePwmSpeed = 140;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= xBoundaryMin)&& (blueActualPosition >= yBoundaryMax)) {
            redMotorDir = INWARD;
            redPwmSpeed = 100;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OUTWARD;
            bluePwmSpeed = 100;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= xBoundaryMin)&& (blueActualPosition <= yBoundaryMin)) {
            redMotorDir = INWARD;
            redPwmSpeed = 100;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = INWARD;
            bluePwmSpeed = 100;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition <= (xBoundaryMin))&& (redActualPosition <= 40) && (blueActualPosition >= yBoundaryMin) && (blueActualPosition <= yBoundaryMax)) {
            redMotorDir = INWARD;
            redPwmSpeed = 200;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition >= (xBoundaryMax)) && (redActualPosition >= 40) && (blueActualPosition >= yBoundaryMin) && (blueActualPosition <= yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 200;
            //redPwmSpeed = (100 +10*(xBoundaryMax - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((blueActualPosition <= (yBoundaryMin))&& (blueActualPosition <= 40) && (redActualPosition >= xBoundaryMin) && (redActualPosition <= xBoundaryMax)) {
            blueMotorDir = INWARD;
            bluePwmSpeed = 230;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else if ((blueActualPosition >= (yBoundaryMax)) && (blueActualPosition >= 40) && (redActualPosition >= xBoundaryMin) && (redActualPosition <= xBoundaryMax)) {
            blueMotorDir = OUTWARD;
            bluePwmSpeed = 230;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
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
    
    break;
    
    //pushes the user outside of the square
    case OUTERSQUARE:
    if ((redActualPosition > (xBoundaryMin-5))&& (redActualPosition < 40) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = OUTWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((redActualPosition < (xBoundaryMax + 5 )) && (redActualPosition >= 40) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
            redMotorDir = INWARD;
            redPwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMax - redActualPosition));
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      }
      else if ((blueActualPosition > (yBoundaryMin-5))&& (blueActualPosition < 40) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)) {
            blueMotorDir = OUTWARD;
            bluePwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
      }
      else if ((blueActualPosition < (yBoundaryMax + 5 )) && (blueActualPosition >= 40) && (redActualPosition > xBoundaryMin) && (redActualPosition < xBoundaryMax)) {
            blueMotorDir = INWARD;
            bluePwmSpeed = 150;
            //redPwmSpeed = (100 +10*(xBoundaryMin - redActualPosition));
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
    //Serial << "x = " << redActualPosition <<", y = " << blueActualPosition << "\n";
    Serial << redActualPosition <<" " << blueActualPosition << "\n";
    break;
    case SQUARE:
    //////////////// work with corners of square
       /*if ((redActualPosition > (xBoundaryMin-10))&& (redActualPosition <= (xBoundaryMin)) && (blueActualPosition > yBoundaryMin) && (blueActualPosition < yBoundaryMax)) {
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
    Serial << redActualPosition <<" " << blueActualPosition << "\n";
    //Serial << "x = " << redActualPosition <<", y = " << blueActualPosition << "\n";
    break;
    case CIRCLE:
        
        /*Serial.print("please input circle parameters...");
        Serial.print("center x position (0 - 83): ");
        int cx = Serial.read();
        Serial.print("center y position (0-83): ");
        int cy = Serial.read();
        Serial.print("radius(0 - 41): ");
        int r = Serial.read();*/
      
       static int dx;
       static int dy;
       static int r = 25;
       static int cx = 40;
       static int cy = 40;
        
        //quadrant 1
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
          if((dx*dx + dy*dy) <= (r*r)){
            blueMotorDir = OUTWARD;
            bluePwmSpeed = (dy/(dx + dy))*totalForce;
            redMotorDir = OUTWARD;
            redPwmSpeed = (dx/(dx+dy))*totalForce;
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
            bluePwmSpeed = (dy/(dx + dy))*totalForce;//(dy/dx)*totalblueForce;
            redMotorDir = OUTWARD;
            redPwmSpeed = (dx/(dx+dy))*totalForce;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
          }
        }
        //quarant 3
        else if((redActualPosition <= cx) && (blueActualPosition <= cy)){
          dx = cx - redActualPosition;
          dy = cy - blueActualPosition;
          if((dx*dx + dy*dy) <= (r*r)){
            blueMotorDir = INWARD;
            bluePwmSpeed = (dy/(dx + dy))*totalForce;//(dy/dx)*totalblueForce;
            redMotorDir = INWARD;
            redPwmSpeed = (dx/(dx+dy))*totalForce;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
          }
        }
        //quadrant 4
        else if((redActualPosition > cx) && (blueActualPosition <= cy)){
          dx = redActualPosition - cx;
          dy = cy - blueActualPosition;
          if((dx*dx + dy*dy) <= (r*r)){
            blueMotorDir = OUTWARD;
            bluePwmSpeed = (dy/(dx + dy))*totalForce;//(dy/dx)*totalblueForce;
            redMotorDir = INWARD;
            redPwmSpeed = (dx/(dx+dy))*totalForce;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
          }
        }
        else{
            blueMotorDir = OFF;
            bluePwmSpeed = 0;
            redMotorDir = OFF;
            redPwmSpeed = 0;
            setRedMotorSpeed(redPwmSpeed, redMotorDir);
            setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
        }
    Serial << "x = " << redActualPosition <<", y = " << blueActualPosition << "\n";
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
    Serial << "x = " << redActualPosition <<", y = " << blueActualPosition << "\n";
    break;
    
    case TRACEBACK:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      break;
    case PATH:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      break;
    case WELL:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      break;
    case HILL:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      break;
    case MOTOROFF:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
        redMotorDir = OFF;
        redPwmSpeed = 0;
        setRedMotorSpeed(redPwmSpeed, redMotorDir);
    break;
    default:
        blueMotorDir = OFF;
        bluePwmSpeed = 0;
        setBlueMotorSpeed(bluePwmSpeed, blueMotorDir);
      
  }

}

