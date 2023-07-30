#include <Arduino.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <WiFiPicker.h>

#include "config.h"

WiFiPicker wifiPicker;

void setup() {
  Serial.begin(115200);
  /**
   * Connet to Wifi
   */
  WiFi.hostname(HOSTNAME);

  wifiPicker.start();
	
  Serial.print("Connected! Ip: ");
  Serial.println(WiFi.localIP());
  /**
   * Enable OTA update
   */
  ArduinoOTA.begin();
}

unsigned int count = 0;

void loop() {
  delay(1000);
  Serial.print("I'm alive for ");
  Serial.print(count++);
  Serial.println(" seconds.");
  // Check for over the air update request and (if present) flash it
  ArduinoOTA.handle();
}