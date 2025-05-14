#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); 
const int flex1Pin = A0; 
const int flex2Pin = A1; 
const int flexThreshold = 950; 
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("Flex sensor message mode ready!");
  BTSerial.println("Bluetooth connected.");
}
void loop() {
  int flex1Value = analogRead(flex1Pin);
  int flex2Value = analogRead(flex2Pin);
  Serial.print("Flex 1: ");
  Serial.print(flex1Value);
  Serial.print(" | Flex 2: ");
  Serial.println(flex2Value);
if (flex1Value > flexThreshold) {
    BTSerial.println("Need Water");
    Serial.println("Sent: Need Water");
    delay(3000);
  }
 if (flex2Value > flexThreshold) {
    BTSerial.println("Good Morning");
    Serial.println("Sent: Good Morning");
    delay(3000);}
delay(1000); 
}
