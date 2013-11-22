
int led = 11;

void setup() {
   pinMode(led, OUTPUT);
}

void loop() {
  for(int i=0;i<3;i++) {
    delay(250);
    digitalWrite(led,HIGH);
    delay(250);
    digitalWrite(led,LOW);
  }
  for(int i=0;i<3;i++) {
    delay(500);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
  }
  for(int i=0;i<3;i++) {
    delay(250);
    digitalWrite(led,HIGH);
    delay(250);
    digitalWrite(led,LOW);
  } 
  delay(2000);
}
