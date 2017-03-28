void readSerialCommand (){
  if (Serial.available()>0){
    
   
    buf[i]= Serial.read(); 
   
    if (int(buf[i])==13 || int(buf[i])==11 ){  //If Carriage return has been reached
     
      int result=atoi(buf);
      Serial.print("angle ");    
      Serial.println(result);     //print the converted char ar
      if(result>180){
      Serial.println("Warning number too big");
      //EXECUTE COMMAND HERE
      }
        
    for(int x=0;x<=3;x++){
    buf[x]=' ';
    }
    i=0;  //start over again
    } //if enter
     i++; 
    } //IF Serial.available
  
 
}

