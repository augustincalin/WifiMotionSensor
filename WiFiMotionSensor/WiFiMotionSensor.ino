#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "GHomeOF";
const char* password = "DICflDmpmp_3m";
const String ID = "MS_1";

boolean PIRstate ;

boolean moveAlreadyDetected = false;

int pinPIR = 0;
int builtInLED = 1;

HTTPClient http;

void setup () {
  Serial.begin(9600);

  Serial.println();
  Serial.printf("Connecting to %s\n", ssid);

  pinMode(builtInLED, OUTPUT);
  pinMode(pinPIR, INPUT);

  WiFi.hostname(ID);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(builtInLED, LOW);
    delay(200);
    digitalWrite(builtInLED, HIGH);
    delay(200);
    Serial.print(".");
  }
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  digitalWrite(builtInLED, HIGH);
}

void loop()
{
  digitalWrite(builtInLED, HIGH);

  PIRstate = digitalRead(pinPIR);
  if (PIRstate == LOW) {
    moveAlreadyDetected = false;
  }

  if (PIRstate == HIGH && !moveAlreadyDetected)
  {
    Serial.println("Move detected...");
    moveAlreadyDetected = true;
    digitalWrite(builtInLED, LOW);

    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("Calling the receiver...");

      http.begin("http://192.168.0.204/motion/on?id=" + ID);
      http.GET();
      http.end();
    }
    digitalWrite(builtInLED, HIGH);

  }

}
