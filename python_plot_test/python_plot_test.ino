/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }

String inputString = "";         // a string to hold incoming data
int inputValue = 0;  // whether the string is complete
int lastValue = inputValue;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  inputString.reserve(200);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    inputValue = inChar - '0';
  }
}
 

// the loop routine runs over and over again forever:
void loop() {
  int edgeSize = 83;
   
  int x = 0;
  int y = 0;
  Serial << inputValue;
  while(inputValue = lastValue){
    switch(inputValue){
      case 1:
          x = 0;
          y = x;
          for(int x = 0; x < edgeSize; x++){
            Serial << x << " " << y << "\n";
            y = (x < edgeSize/2)? ++y : --y;
            delay(50);
          }
        break;
      case 2:
          x = 0;
          y = x;
          for(int x = 0; x < edgeSize; x++){
            Serial << x << " " << y << "\n";
            y = 10;
            delay(50);
          }
        break;
      case 3:
        break;       
      case 4:
        break;       
      case 5:
        break;       
      case 6:
        break;       
      case 7:
        break;       
      default:
        break;
      }
    }

    lastValue = inputValue;
  }
