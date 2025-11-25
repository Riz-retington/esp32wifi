#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "Acculamator";
const char* password = "acculator";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
  Serial.print("My IP = ");
  Serial.println(WiFi.localIP());

  Serial.print("Submask = ");
  Serial.println(WiFi.subnetMask());
}

void loop() {
}