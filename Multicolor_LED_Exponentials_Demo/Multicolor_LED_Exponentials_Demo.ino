#include <Time.h>

//RGB LED pins
int ledDigitalOne[] = {9, 10, 11}; //9 = redPin, 10 = greenPin, 11 = bluePin
int bluePin = 6; 
int redPin = 5;
int greenPin = 3;

const boolean ON = LOW;  
const boolean OFF = HIGH;

void setup(){
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  float max_range = 1023.0;
  float seconds = (float(millis())/1000.0);
  float range_conversion = max_range/8.0;
  
  float red = 1023-(((exp(-pow(((seconds-10.0)/5.0),2.0))*(seconds/6.5)))*range_conversion);
  float green = 1023-(((1.0/(1.0+exp(-((seconds-14.0)/1.25)))+0.1*exp(-pow(((seconds-5.0)/2.0),2))))*range_conversion);
  float blue = 1023-(((1.0/(1.0+exp(-((seconds-14.0)/1.25)))+0.1*exp(-pow(((seconds-5.0)/2.0),2))))*range_conversion);
  
  analogWrite(bluePin, 1023-blue);
  analogWrite(redPin, 1023-red);
  analogWrite(greenPin, 1023-green);
  
  analogWrite(ledDigitalOne[0], red);
  analogWrite(ledDigitalOne[1], green);
  analogWrite(ledDigitalOne[2], blue);
  
  Serial.println(analogRead(redPin));
  
}
