// motor 1 is bottom
// motor 2 is top
#define stepPin1 15
#define dirPin1 32
#define stepPin2 27
#define dirPin2 33

void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop() {
  digitalWrite(dirPin1,HIGH);
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(1000);
  }
  delay(2000); // 2 second delay

  digitalWrite(dirPin2,LOW); //lower
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1000);
  }

  // turn on EM
  
  digitalWrite(dirPin2, HIGH); // raise
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1000);
  }

  delay(2000); // 2 second delay

  digitalWrite(dirPin1, LOW); // change direction
  for (int x = 0; x<200; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(1000);
  }
  delay(10000);
}
