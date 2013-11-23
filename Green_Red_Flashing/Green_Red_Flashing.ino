
int green = 9;
int red = 8;

void case1(int i) {
  if (i%2==0) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
}

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT); 
}

void loop() {
  for(int i = 0; i<50; i++) {
  case1(i);
  delay(100);
  }
}
