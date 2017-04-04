void setupPosition (int desiredPositionX, int desiredPositionY){

 static int tempX;
 static int tempY;
 static double xSpeed;
 static double ySpeed;
 
 while(redActualPosition != desiredPositionX  &&  blueActualPosition != desiredPositionY){
            tempX= redActualPosition;
            xSpeed = redComputeHapticPath(tempX,desiredPositionX );
            xSpeed = (int)(120 + abs(xSpeed)/3); 
            if(xSpeed > 0 && (xSpeed < 255)) {
              redMotorDir = INWARD;//OUTWARD;
              xSpeed = (int)(120 + abs(xSpeed)/3); 
              setRedMotorSpeed(xSpeed, redMotorDir);
            }
            else if(xSpeed < 0 && (xSpeed > -255)) {
              redMotorDir = OUTWARD;
              xSpeed = (int)(120 + abs(xSpeed)/3); 
              setRedMotorSpeed(xSpeed, redMotorDir);
            }
            else {
              redMotorDir = OFF;
              setRedMotorSpeed(0, redMotorDir);
            }
              
            
            tempY= blueActualPosition;
            ySpeed = blueComputeHapticPath(tempY, desiredPositionY);
            if(ySpeed > 0 && ySpeed < 255) {
              blueMotorDir = INWARD;//OUTWARD;
              ySpeed = (int)(120 + ySpeed/3);
              setBlueMotorSpeed(ySpeed, blueMotorDir); 
            }
            else if(ySpeed < 0 && ySpeed > -255){
              blueMotorDir = OUTWARD;
              ySpeed = (int)(120 + abs(ySpeed)/3); 
              setBlueMotorSpeed(ySpeed, blueMotorDir);
            }
            else {
              blueMotorDir = OFF;
              setBlueMotorSpeed(0, blueMotorDir);
            }
   
    }
    redMotorDir = OFF;
    blueMotorDir = OFF;
    setRedMotorSpeed(0, blueMotorDir);
    setBlueMotorSpeed(0, blueMotorDir);
}

