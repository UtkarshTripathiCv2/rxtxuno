#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

const int buttonPin = 2;

void setup() {
  driver.init();
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    const char *msg = "1";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
  } else {
    const char *msg = "0";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
  }

  delay(100);
}
