#include <Arduino.h>
#include <AntiDelay.h>

// Create an AntiDelay object with a 1 second interval
AntiDelay antiDelay(1000);

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(115200);
}

void loop() {
  // Check if the delay has finished
  if (antiDelay) {
    Serial.println("Delay finished");
  }

  // Check if the timer is running
  if (antiDelay.isRunning()) {
    Serial.println("Timer is running");
  } else {
    Serial.println("Timer is not running");
  }

  // Pause timer then check if it is running
  antiDelay.pause();
  if (antiDelay.isRunning()) {
    Serial.println("Timer is running");
  } else {
    Serial.println("Timer is paused");
  }

  // Resume timer
  antiDelay.resume();
  if (antiDelay.isRunning()) {
    Serial.println("Timer is resumed");
  } else {
    Serial.println("Timer is not running");
  }

  // Reset timer
  antiDelay.reset();
  Serial.println("Timer is reset");

  // Change antiDelay interval to 2 seconds
  antiDelay.setInterval(2000);
  Serial.println("Interval is set to 2 seconds");
}