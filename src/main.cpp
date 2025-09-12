#include <Arduino.h>
#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>
#include <RTC.h>
ArduinoLEDMatrix matrix; // Create an instance of the ArduinoLEDMatrix class

#define ARDUINO_GRAPHICS_DEFAULT_COLOR 0xFFFFFF // Default for Graphics Library to Write as On

void setup() {
    Serial.begin(115200);
    matrix.begin();
    RTC.begin();
    int dayOfMonth = 10;
    int year = 2024;
    int hourInMilitaryTime = 14;
    int minute = 30;
    int second = 0;
    RTCTime startTime(dayOfMonth, Month::JUNE, year, hourInMilitaryTime, minute, second, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
    RTC.setTime(startTime);
}


void loop() {
    RTCTime currentTime;
    // Get current time from RTC
    RTC.getTime(currentTime);
    int hour = currentTime.getHour();
    int minutes = currentTime.getMinutes();
    int seconds = currentTime.getSeconds();
    String spacesBuffer = " ";
    String currentTimeMessage = spacesBuffer + "The current time is " + String(hour) + ":" + String(minutes) + ":" + String(seconds) + spacesBuffer;
    int fiftyMilliseconds = 50;
    int hundredMilliseconds = 100;
    matrix.beginDraw();
    matrix.stroke(ARDUINO_GRAPHICS_DEFAULT_COLOR);
    matrix.textScrollSpeed(hundredMilliseconds);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, ARDUINO_GRAPHICS_DEFAULT_COLOR);
    matrix.println(currentTimeMessage);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
}