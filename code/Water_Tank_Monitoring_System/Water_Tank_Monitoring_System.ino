#define BLYNK_TEMPLATE_ID "TMPL3iP7onVOO"
#define BLYNK_TEMPLATE_NAME "Water Level Indicator"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define waterSensorPin A0
#define led1Pin D2
#define led2Pin D3
#define led3Pin D6
#define led4Pin D10
#include "BlynkEdgent.h"



void setup() {
  pinMode(waterSensorPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  int waterLevel = analogRead(waterSensorPin);
  Serial.print("Water Level Analog Reading: ");
  Serial.println(waterLevel);
  
  Blynk.virtualWrite(V0, waterLevel); // Send water level reading to Blynk app
  
  // LED control logic...
  if (waterLevel < 200) {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  } else if (waterLevel >= 200 && waterLevel < 600) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  } else if (waterLevel >= 600 && waterLevel < 630) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  } else if (waterLevel >= 630 && waterLevel < 635) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, LOW);
  } else if (waterLevel >= 635) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, HIGH);
  } else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  }

  delay(500); 
}
