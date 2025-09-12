#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

#define MAX_ROW 8
#define MAX_COL 12

ArduinoLEDMatrix matrix; // Create an instance of the ArduinoLEDMatrix class
byte frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  // Initialize the LED matrix
  matrix.begin();
  matrix.renderBitmap(frame, MAX_ROW, MAX_COL);
}

void loop() {
  const unsigned long delay_in_ms = 100;
  for (int i = 0; i < MAX_ROW; i++) {
    for (int j = 0; j < MAX_COL; j++) {
      frame[i][j] = ~frame[i][j];
      matrix.renderBitmap(frame, MAX_ROW, MAX_COL);
      delay(delay_in_ms);
    }
  }
}