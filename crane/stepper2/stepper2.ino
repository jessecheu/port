// motor 1 is bottom
#define stepPin1 15
#define dirPin1 32
// motor 2 is top
#define stepPin2 27
#define dirPin2 33
// Ultrasonic Sensor
// #define trigPin 17
// #define echoPin 21
// // Electromagnet
// #define emPin 23

float duration, distance;

void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
  // pinMode(emPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  
  Serial.println("Move M1");
  digitalWrite(dirPin1,HIGH);
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(20000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(20000);
  }
  delay(2000); // 2 second delay

  Serial.println("Lower M2");
  digitalWrite(dirPin2,LOW); //lower
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(8000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(8000);
  }
  delay(2000);

  // turn on EM

  Serial.println("Raise M2");
  digitalWrite(dirPin2, HIGH); // raise
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(8000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(8000);
  }
  delay(2000); // 2 second delay

  Serial.println("Bring back M1");
  digitalWrite(dirPin1, LOW); // change direction
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(20000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(20000);
  }
  delay(3000);

  // lower M2
  // turn off EM
  // raise M2
}
