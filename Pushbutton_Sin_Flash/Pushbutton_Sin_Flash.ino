
int ledPin = 9;
int buttonPin = 2;
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  float time = millis();
  val = digitalRead(buttonPin);
  if (val == HIGH) {
  digitalWrite(ledPin, LOW);
  }
  else {
  analogWrite(ledPin, (250/2)*(sin(time/500)+1));
  }
}

