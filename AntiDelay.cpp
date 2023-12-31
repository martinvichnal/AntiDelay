#include "Arduino.h"
#include "AntiDelay.h"

AntiDelay::AntiDelay(unsigned long interval) : timeInterval(interval), previousMillis(0), isPaused(false), pauseOffset(0) {}

AntiDelay::operator bool() {
  if (isPaused) return false;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= timeInterval) {
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}

void AntiDelay::reset() {
  previousMillis = millis();
}

void AntiDelay::setInterval(unsigned long interval) {
  timeInterval = interval;
}

void AntiDelay::pause() {
  pauseOffset = millis() - previousMillis;
  isPaused = true;
}

void AntiDelay::resume() {
  if (isPaused) {
    previousMillis = millis() - pauseOffset;
    isPaused = false;
  }
}

bool AntiDelay::isRunning() {
  return !isPaused && millis() - previousMillis < timeInterval;
}