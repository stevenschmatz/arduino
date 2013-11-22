/*
  Blink
  Turns on an LED on for one second, then off for one second.
*/

// Pin 13 has an LED connected on most Arduino boards.


int led = 11;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int i = 0;
  int maximum = 1000;
  while (i < maximum){
    digitalWrite(led, HIGH);
    delay(i*i);
    digitalWrite(led, LOW);
    delay(i*i);
    i++;
  }
}
