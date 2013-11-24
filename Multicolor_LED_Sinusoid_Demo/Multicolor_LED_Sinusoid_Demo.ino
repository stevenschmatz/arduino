#include <Time.h>

//RGB LED pins
int ledDigitalOne[] = {9, 10, 11}; //9 = redPin, 10 = greenPin, 11 = bluePin
int ledPin = 6;                                   

const boolean ON = LOW;  
const boolean OFF = HIGH;

void setup(){
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  float max_range = 1023.0;
  float seconds = (float(millis())/1000.0);
  
  float red = (cos(seconds/2)+1)*max_range/8.0;
  float green = (cos(seconds/3)+1)*max_range/8.0;
  float blue = (cos(seconds)+1)*max_range/8.0;
  
  analogWrite(ledPin, 0);
  
  analogWrite(ledDigitalOne[0], red);
  analogWrite(ledDigitalOne[1], green);
  analogWrite(ledDigitalOne[2], blue);
  
}
