#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <RH_ASK.h>
#include <SPI.h>
ESP8266WebServer server(80);
RH_ASK driver(2000, 4, 5, 0);
#include "functions.h"
#include "adresses.h"

void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
  }
  Serial.println("Device with IP Address: " + WiFi.localIP().toString() + " connected to WiFi.");
  driver.init();
  server.on("/", IndexPage);
  server.on("/textPage", TextPage);
  server.on("/api-indexPage", api_IndexPage);
  server.on("/api-textPage", api_TextPage);
  server.begin();
}

void loop() 
{
  server.handleClient();
}
