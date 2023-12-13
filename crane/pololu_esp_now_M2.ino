#include <esp_now.h>
#include <WiFi.h>

#include "BluetoothSerial.h"
#include <HardwareSerial.h>

uint8_t broadcastAddress1[] = {0x94, 0xB9, 0x7E, 0x6B, 0xA6, 0x08}; //C1
uint8_t broadcastAddress2[] = {0x94, 0xB9, 0x7E, 0x6B, 0xA7, 0x30}; //C2
uint8_t broadcastAddress3[] = {0x94, 0xE6, 0x86, 0x90, 0x85, 0x84}; // M1

typedef struct test_struct {
  int num;
  int signal;
  int zone;
} test_struct;

test_struct myPololu;
test_struct otherPololu;

HardwareSerial UARTPort(1);

char uart_temp;
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
  memcpy(&otherPololu, incomingData, sizeof(otherPololu));
  Serial.print("Bytes received: ");
  Serial.println(len);
  if((myPololu.zone - otherPololu.zone) == -1) {
    UARTPort.write('S');
  }
  else {
    UARTPort.write('C');
  }
}

void setup() {
  Serial.begin(115200);
  myPololu.signal = 0;
  myPololu.num = 1; //M1
  myPololu.zone = 3;
  UARTPort.begin(115200, SERIAL_8N1, 16, 17);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);
  // register peer
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  // register first peer  
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  // register second peer  
  memcpy(peerInfo.peer_addr, broadcastAddress2, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  memcpy(peerInfo.peer_addr, broadcastAddress3, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
void loop() {
  if(UARTPort.available()) {
    if(uart_temp == 'L') {
      myPololu.signal = 1;
      Serial.print("Received UART Signal: ");
      Serial.println("L");
    }
    else if(uart_temp == 'Z') {
      myPololu.zone += 1;
      myPololu.signal = 2;
      Serial.print("Entered new zone: ");
      Serial.println(myPololu.zone);
    }
  }
  else {
    myPololu.signal = 0;
  }
  if(myPololu.signal != 0) {
    esp_err_t result = esp_now_send(0, (uint8_t *) &myPololu, sizeof(myPololu));
    if (result == ESP_OK) {
      Serial.println("Sent with success");
    }
    else {
      Serial.println("Error sending data");
    }
    myPololu.signal = 0;
  }

   
  
  // input = SerialBT.read();
  // if (input == 'L') {
  //   Serial.println("Received BT Signal: L");
  //   UARTPort.write(input);
  //   Serial.println("Transmitted UART signal: L");
  //   SerialBT.write('P');
  // }
}