#include <Arduino.h>

// put function declarations here:
constexpr unsigned long convert_seconds_to_milliseconds(const unsigned long seconds);


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  const unsigned long one_second = convert_seconds_to_milliseconds(1);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(one_second);
  digitalWrite(LED_BUILTIN, LOW);
  delay(one_second);
}


// put function definitions here:
constexpr unsigned long convert_seconds_to_milliseconds(const unsigned long seconds){
  return seconds * 1000;
}