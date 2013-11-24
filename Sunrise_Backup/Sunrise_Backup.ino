#include <Time.h>

//Arguments
float durationMinutes = 1.0; //The duration of the light progression, in minutes.

int plugInHour = 22; //The hours at 10pm, 24 hour time
int plugInMinute = 00; //The minutes at 10:00pm
int wakeHour = 22; //6am
int wakeMinute = 01; // 6:00am

int secondsUntilWake(int plugInHour, int plugInMinute, int wakeHour, int wakeMinute) {  
  int hour1;
  int hours;
  int minute1;
  int minutes;
  
  if (plugInHour > wakeHour) {
    hour1 = (24-plugInHour);
    hours = wakeHour+hour1;
  }
  else if (plugInHour < wakeHour) {
    hours = wakeHour-plugInHour;
  }
  else if (plugInHour == wakeHour) {
    hours = 0;
  }
  
  if (plugInMinute > wakeMinute) {
    minute1 = (60-plugInMinute);
    minutes = wakeMinute+minute1;
  }
  else if (plugInMinute < wakeMinute) {
    minutes = wakeMinute-plugInMinute;
  }
  else if (plugInMinute == wakeMinute) {
    minutes = 0;
  }
  return 60*((60*hours)+minutes);
}


//RGB LED pins
int ledDigitalOne[] = {9, 10, 11}; //9 = redPin, 10 = greenPin, 11 = bluePin
int bluePin = 6; 
int redPin = 5;
int greenPin = 3;

const boolean ON = LOW;  
const boolean OFF = HIGH;

void setup(){
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT); 
  }
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  
}


void loop(){
  float max_range = 1023.0;
  float secondsUntilStart = secondsUntilWake(plugInHour, plugInMinute, wakeHour, wakeMinute)-(durationMinutes*60);
  float seconds = (float(millis())/1000.0)-secondsUntilStart;
  seconds = seconds/(durationMinutes*3.0);
  float range_conversion = max_range/8.0;
  
  Serial.println(seconds); 
  
  float red = 1023-(((exp(-pow(((seconds-10.0)/5.0),2.0))*(seconds/6.5)))*range_conversion);
  float green = 1023-(((1.0/(1.0+exp(-((seconds-14.0)/1.25)))+0.1*exp(-pow(((seconds-5.0)/2.0),2))))*range_conversion);
  float blue = 1023-(((1.0/(1.0+exp(-((seconds-14.0)/1.25)))+0.1*exp(-pow(((seconds-5.0)/2.0),2))))*range_conversion);
  
  analogWrite(bluePin, 1023-blue);
  analogWrite(redPin, 1023-red);
  analogWrite(greenPin, 1023-green);
  
  analogWrite(ledDigitalOne[0], red);
  analogWrite(ledDigitalOne[1], green);
  analogWrite(ledDigitalOne[2], blue);
  
 
}



