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
#include "Ultrasonic.h"

Ultrasonic ultrasonic(17);

uint8_t broadcastAddress1[] = {0x94, 0xE6, 0x86, 0x90, 0x85, 0x84}; // M1
uint8_t broadcastAddress2[] = {0xB8, 0xD6, 0x1A, 0x0C, 0x95, 0x50}; // M2

long distance;
typedef struct pololu {
  int num;
  int signal;
  int zone;
} pololu;

pololu myData;

pololu sendData;

esp_now_peer_info_t peerInfo;
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  Serial.print("Packet to: ");
  // Copies the sender mac address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  distance = ultrasonic.MeasureInCentimeters();
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Signal received: ");
  Serial.println(myData.signal);

  if(myData.signal == 1 && distance < 10 && myData.zone%5 == 0) {
    Serial.println("Timer Triggered");
    timer();
  }
  else {
  Serial.println(distance);
    Serial.println(myData.zone);
  }
}
void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_send_cb(OnDataSent);

  esp_now_register_recv_cb(OnDataRecv);

  peerInfo.channel = 0;  
  peerInfo.encrypt = false;

  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  memcpy(peerInfo.peer_addr, broadcastAddress2, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(emPin, OUTPUT);
}

void loop() {
  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);

  // duration = pulseIn(echoPin, HIGH);
  // distance = ultrasonic.MeasureInCentimeters();
  // Serial.println(distance);
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
  Serial.println("Lower M2");
  digitalWrite(dirPin2,LOW); //lower
  // turn on EM
  digitalWrite(emPin, HIGH);
  Serial.println("EM on");
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(20000);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(20000);
  }
  delay(2000); // 2 second delay

  Serial.println("Raise M2");
  digitalWrite(dirPin2, HIGH); // raise
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(20000);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(20000);
  }
  delay(2000); // 2 second delay

  Serial.println("Move M1");
  digitalWrite(dirPin1,HIGH);
  for (int x = 0; x<100; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(20000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(20000);
  }

  delay(2000); // 2 second delay
  // lower M2
  Serial.println("Lower M2");
  digitalWrite(dirPin2,LOW); //lower
  
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(20000);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(20000);
  }
  digitalWrite(emPin, LOW);
  // turn off EM
  Serial.println("EM off");
  delay(2000);

    Serial.println("Raise M2");
  digitalWrite(dirPin2, HIGH); // raise
  for (int x = 0; x<50; x++) {
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(20000);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(20000);
  }
  delay(2000); // 2 second delay


  Serial.println("Bring back M1");
  digitalWrite(dirPin1, LOW); // change direction
  for (int x = 0; x<100; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(20000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(20000);
  }
  delay(1000);
  sendData.signal = 9;
  esp_err_t result = esp_now_send(0, (uint8_t *) &sendData, sizeof(sendData));
    if (result == ESP_OK) {
      Serial.println("Sent with success");
    }
    else {
      Serial.println("Error sending data");
    }
}

void timer() {
  delay(5000);
  sendData.signal = 9;
  esp_err_t result = esp_now_send(0, (uint8_t *) &sendData, sizeof(sendData));
    if (result == ESP_OK) {
      Serial.println("Sent with success");
    }
    else {
      Serial.println("Error sending data");
    }
}