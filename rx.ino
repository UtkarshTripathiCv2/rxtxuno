#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

const int ledPin = 3;

unsigned long lastSignalTime = 0;
const int timeout = 500; // ms

void setup() {
  driver.init();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // start OFF
}

void loop() {
  uint8_t buf[10];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    if (buf[0] == '1') {
      digitalWrite(ledPin, HIGH);
      lastSignalTime = millis();
    } 
    else if (buf[0] == '0') {
      digitalWrite(ledPin, LOW);
      lastSignalTime = millis();
    }
  }

  // 🔥 Timeout safety (VERY IMPORTANT)
  if (millis() - lastSignalTime > timeout) {
    digitalWrite(ledPin, LOW);
  }
}
