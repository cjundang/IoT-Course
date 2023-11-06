#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "cj";
const char* password = "1234567890";

unsigned long channelID = 1486243;
const char* writeKey = "L154EEQBB11DEPM3";

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

WiFiClient  client;

void setup() {
  Serial.begin(115200);   
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);   
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }
    int value = analogRead(A0);
    Serial.print("Value: ");
    Serial.println(value);
    int x = ThingSpeak.writeField(channelID, 2, value, writeKey);
    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}

