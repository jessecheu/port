// motor 1 is bottom
// motor 2 is top

#define stepPin1 27
#define dirPin1 33
#define stepPin2 15
#define dirPin2 32

void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println("Move M1");
  digitalWrite(dirPin1,HIGH);
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(4000);
  }
  delay(2000); // 2 second delay

  Serial.println("Lower M2");
  digitalWrite(dirPin2,LOW); //lower
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(4000);
  }
  delay(2000);

  // turn on EM

  Serial.println("Raise M2");
  digitalWrite(dirPin2, HIGH); // raise
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(4000);
  }
  delay(2000); // 2 second delay

  Serial.println("Bring back M1");
  digitalWrite(dirPin1, LOW); // change direction
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(4000);
  }
  delay(5000);

  // lower M2
  // turn off EM
  // raise M2
}
