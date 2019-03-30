#include <Arduino.h>

#ifdef ESP8266
#include <ESP8266WiFi.h> 
#include <ESP8266mDNS.h>

const char* mdns_name = "chicken8266";

#endif

#ifdef ESP32
#include <WiFi.h> 
#include <ESPmDNS.h>

const char* mdns_name = "chicken32";

#endif


const char* ssid = "YOUR WIFI SSID";
const char* password = "YOUR WIFI PASSWORD";

void setup() {
  Serial.begin(115200);

  Serial.println("[wifi]");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if(!MDNS.begin(mdns_name))
    Serial.println("Error setting up MDNS responder!");
  else
    Serial.printf("mDNS responder started: %s\n", mdns_name);
}

void loop() {
}

