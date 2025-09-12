#include <Arduino.h>
#include <Arduino_LED_Matrix.h>
#include "four_frames.h"

ArduinoLEDMatrix matrix; // Create an instance of the ArduinoLEDMatrix class

const uint32_t happy_frame[3] = {
    0x19819,
    0x80000001,
    0x81f8000
};

// 0b110001100001001010010001000100
// 0b1000010000010000001000100000000
// 0b10100000000001000000000000000000
const unsigned long heart_frame[3] = {
  0x3184a444,
  0x42081100,
  0xa0040000};



void setup() {
  matrix.begin();
  matrix.loadWrapper(four_frames, 4);
  matrix.play(false);
  delay(2000);
}

void loop() {
  matrix.loadFrame(happy_frame);
  delay(500);

  matrix.loadFrame(heart_frame);
  delay(500);
}
