#include <Arduino.h>
#include <WebServer.h>
#define LED 2

const char* ssid = "Acculamator";
const char* password = "acculator";
const byte Led= 2;
WebServer server(80);

void handleRoot(){
  String HTML = "<a href=\"/on\">開啟LED</a> <br>";
  HTML += "<a href=\"/on\">關閉LED</a>";
  server.send(200, "text/html; charset=UTF-8", HTML);
}

void handleNotFound(){
  server.send(404, "text/plain; charset=UTF-8", "找不到檔案");
}

void handleLedOn(){
 digitalWrite(LED, HIGH);
}

void handleLedOff(){
  digitalWrite(LED, LOW);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(LED, OUTPUT);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected!!");
  Serial.print("My IP = ");
  Serial.println(WiFi.localIP());

  server.on("/",handleRoot);
  server.on("/on",handleLedOn);
  server.on("/off",handleLedOff);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Server is running...");
}

void loop() {
  server.handleClient();
}
