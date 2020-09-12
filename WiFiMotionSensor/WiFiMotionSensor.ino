#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "home.of"; //Your WiFI ssid
const char* password = "DICflDmpmp_3m"; //Your WiFi password
boolean PIRstate ; //variable to store PIR state
boolean moveAlreadyDetected = false;

int pinPIR = 0;
int builtInLED = 1;

HTTPClient http;

void setup () {
  pinMode(builtInLED, OUTPUT);
  pinMode(pinPIR, INPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(builtInLED, LOW);
    delay(200);
    digitalWrite(builtInLED, HIGH);
    delay(200);
  }
  digitalWrite(builtInLED, HIGH);
}

void loop()
{
  digitalWrite(builtInLED, HIGH);

  PIRstate = digitalRead(pinPIR);  //HIGH when motion detected, else LOW
  if (PIRstate == LOW) {
    moveAlreadyDetected = false;
  }

  if (PIRstate == HIGH && !moveAlreadyDetected)
  {
    moveAlreadyDetected = true;

    if (WiFi.status() == WL_CONNECTED)
    {
      

      http.begin("http://192.168.0.204/5/on");
      http.GET();
      http.end();
      for (int i = 0; i < 3; i++) {
        digitalWrite(builtInLED, LOW);
        delay(100);
        digitalWrite(builtInLED, HIGH);
        delay(100);
      }

    }
  }

}
