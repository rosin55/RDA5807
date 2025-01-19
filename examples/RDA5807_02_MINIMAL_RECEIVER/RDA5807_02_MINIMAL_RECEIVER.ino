#include <RDA5807.h> // It is a minimal receicer with two push buttons (ATmega328 - Uno, Nano etc)
RDA5807 rx; 
void setup() {
  pinMode(2, INPUT_PULLUP); // Arduino pin 4 - Seek station down
  pinMode(3, INPUT_PULLUP); // Arduino pin 5 - Seek station up
  rx.setup(); // Starts the receiver with default parameters
  rx.setFrequency(8830); // Tunes in 88.3 MHz  - Switch to your local favorite station
}
void loop() {
  if (digitalRead(2) == LOW) rx.seek(RDA_SEEK_WRAP,RDA_SEEK_DOWN);
  if (digitalRead(3) == LOW) rx.seek(RDA_SEEK_WRAP,RDA_SEEK_UP);
  delay(200);
}