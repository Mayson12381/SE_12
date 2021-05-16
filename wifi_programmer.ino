#include "ESP8266WiFi.h"
#include <ESP8266HTTPClient.h>

#define inputOn    D1
#define inputOff    D2
#define internal_led    D4

int inputOnState = 0;
int inputOffState = 0;

// replace with wifi name
char ssid[] = "**";
// replace with wifi password
char pass[] = "**";

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(inputOn, INPUT);
  pinMode(inputOff, INPUT);
  pinMode(internal_led, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  digitalWrite(internal_led, HIGH);
}

void loop() {
  inputOnState = digitalRead(inputOn);
  inputOffState = digitalRead(inputOff);

  if (inputOnState == HIGH) {
    digitalWrite(internal_led, LOW);
    changeLampState("https://maker.ifttt.com/trigger/floorLampOn/with/key/k-bTh86GZtOKBPCtD9Q3GpfDaEZjlwncz1Hif1XCEYR");
  } else if (inputOffState == HIGH) {
    digitalWrite(internal_led, LOW);
    changeLampState("https://maker.ifttt.com/trigger/floorLampOff/with/key/k-bTh86GZtOKBPCtD9Q3GpfDaEZjlwncz1Hif1XCEYR");
  } else {
    digitalWrite(internal_led, HIGH);
  }
  
  delay(100);
}

void changeLampState(String url) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client; HTTPClient http;

    client.setInsecure();
    client.connect(url, 443);
    http.begin(client, url);
    int httpCode = http.POST("");
    String payload = http.getString();
    http.end();
  }
}
