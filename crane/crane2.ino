//Motors, Ultrasonic Sensor, 
// motor 1 is bottom
#define stepPin1 27 //15
#define dirPin1 33 //32
// motor 2 is top
#define stepPin2 15 //27
#define dirPin2 32 //33
// Ultrasonic Sensor
#define trigPin 17
#define echoPin 21
// // Electromagnet
#define emPin 23

#include "BluetoothSerial.h"
#include <esp_now.h>
#include <WiFi.h>

String device_name = "Crane2";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
  #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
char command = ' ';


float duration, distance;
typedef struct pololu {
  int num;
  char signal;
} pololu;

pololu myData;
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Signal received: ");
  Serial.println(myData.signal);

  if(myData.signal == 'L' && distance < 30) {
    dropPayload();
  }
}
void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  SerialBT.begin(device_name); //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());

  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(emPin, OUTPUT);
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
  // delay(100);
//   if(SerialBT.available()) {
//     command = getBTCommand();
//   }
//   if(command == 'D' & distance < 30) {
//     dropPayload();
//     command = ' ';
//     while(command == ' ') {
//       command = SerialBT.read();
//     }
//   }
//   else if(getBTCommand() == 'P') {

//   }
//   else {
//     serial.println("crane2 off")
//   }
// }


// char getBTCommand() {
//   if (SerialBT.available()) {
//     //Serial.print("Reading Bluetooth");
//     char BTinput = SerialBT.read();
//     //Serial.print(BTinput);
//     return BTinput;
//   }
 }


void dropPayload() {
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
  digitalWrite(dirPin2,HIGH); //lower
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
  digitalWrite(dirPin2, LOW); // raise
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
  digitalWrite(dirPin2,HIGH); //lower
  
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
  digitalWrite(dirPin2, LOW); // raise
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(20000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(20000);
  }
  delay(1000); // 2 second delay
}