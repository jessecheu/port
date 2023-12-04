// motor 1 is bottom
#define stepPin1 15
#define dirPin1 32
// motor 2 is top
#define stepPin2 27
#define dirPin2 33
// Ultrasonic Sensor
#define trigPin 17
#define echoPin 21
// // Electromagnet
#define emPin 23

float duration, distance;

void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(emPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  // Serial.print("Distance: ");
  // Serial.println(distance);
  delay(100);

  if (distance <30) {
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
    // turn on EM
    digitalWrite(emPin, HIGH);
    Serial.println("EM on");
    for (int x = 0; x<50; x++) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(20000);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(20000);
    }
    delay(2000);

    Serial.println("Raise M2");
    digitalWrite(dirPin2, HIGH); // raise
    for (int x = 0; x<50; x++) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(20000);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(20000);
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
    delay(1000);

    // lower M2
    Serial.println("Lower M2");
    digitalWrite(dirPin2,LOW); //lower
    
    for (int x = 0; x<50; x++) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(20000);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(20000);
    }
    digitalWrite(emPin, LOW);
    // turn off EM
    Serial.println("EM off");
    delay(2000);

    // raise M2
    Serial.println("Raise M2");
    digitalWrite(dirPin2, HIGH); // raise
    for (int x = 0; x<50; x++) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(20000);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(20000);
    }
    delay(1000); // 2 second delay
  }
  else {
    Serial.println("off");
  }
}
