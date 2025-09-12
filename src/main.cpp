#include <Arduino.h>
#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>

ArduinoLEDMatrix matrix; // Create an instance of the ArduinoLEDMatrix class

#define ARDUINO_GRAPHICS_DEFAULT_COLOR 0xFFFFFF // Default for Graphics Library to Write as On

void setup() {
  matrix.begin();
}

void loop() {
  char message[] = " The current time is 00:00:00 ";
  int one_hundred_ms = 100;
  matrix.beginDraw();
  matrix.stroke(ARDUINO_GRAPHICS_DEFAULT_COLOR);
  matrix.textScrollSpeed(one_hundred_ms);
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, ARDUINO_GRAPHICS_DEFAULT_COLOR);
  matrix.println(message);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}
