#include <Arduino.h>
#include <WebServer.h>

const char* ssid = "Acculamator";
const char* password = "acculator";

WebServer server(80);

void handleRoot(){
  server.send(200, "text/html; charset=UTF-8", "Hello World");
}

void handleNotFound(){
  server.send(404, "text/plain; charset=UTF-8", "找不到檔案");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected!!");
  Serial.print("My IP = ");
  Serial.println(WiFi.localIP());

  server.on("/",handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Server is running...");
}

void loop() {
  server.handleClient();
}
