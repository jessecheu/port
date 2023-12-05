#include "BluetoothSerial.h"
#define stepPin1 27
#define dirPin1 33
#define stepPin2 15
#define dirPin2 32

String device_name = "Crane 2";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
  #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

char command = ' ';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(SerialBT.available()) {
    command = getBTCommand();
  }
  if(command == 'D') {
    dropPayload();
    command = ' ';
    while(command == ' ') {
      command = SerialBT.read();
    }
  }
  else if(getBTCommand() == 'P') {

  }
}

char getBTCommand() {
  if (SerialBT.available()) {
    //Serial.print("Reading Bluetooth");
    char BTinput = SerialBT.read();
    //Serial.print(BTinput);
    return BTinput;
  }
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
  SerialBT.write('L');
}