/**
 * @file AntiDelay.cpp
 * @author Martin Vichnál
 * @page https://github.com/martinvichnal/AntiDelay
 * @brief AntiDelay is a library that aims to provide non-blocking delay functionality.
 * @version v1.1.2
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2024
 */

#include "AntiDelay.h"

/**
 * @brief Constructs an instance of the AntiDelay class.
 *
 * @param interval in milliseconds
 */
AntiDelay::AntiDelay(unsigned long interval) : timeInterval(interval), previousMillis(0), isPaused(false), pauseOffset(0) {}

/**
 * @brief Converts the AntiDelay object to a boolean value.
 *
 * This operator overloads the conversion of the AntiDelay object to a boolean value.
 * It returns true if the specified time interval has elapsed since the last call,
 * otherwise it returns false. If the AntiDelay object is paused, it always returns false.
 *
 * @return true if the time interval has elapsed, false otherwise.
 */
AntiDelay::operator bool()
{
  if (isPaused)
    return false;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= timeInterval)
  {
    previousMillis = currentMillis;
    return true;
  }
  else
  {
    return false;
  }
}

/**
 * @brief Resets the AntiDelay timer by updating the previousMillis variable.
 */
void AntiDelay::reset()
{
  previousMillis = millis();
}

/**
 * @brief Sets the time interval for the AntiDelay object.
 *
 * This function sets the time interval, in milliseconds, for the AntiDelay object.
 * The time interval determines the delay between consecutive actions performed by the AntiDelay object.
 *
 * @param interval in milliseconds
 */
void AntiDelay::setInterval(unsigned long interval)
{
  timeInterval = interval;
}

/**
 * @brief Pauses the AntiDelay timer.
 * Calculates the pause offset by subtracting the previousMillis from the current millis.
 * Sets the isPaused flag to true.
 */
void AntiDelay::pause()
{
  pauseOffset = millis() - previousMillis;
  isPaused = true;
}

/**
 * @brief Resumes the AntiDelay timer if it is currently paused.
 */
void AntiDelay::resume()
{
  if (isPaused)
  {
    previousMillis = millis() - pauseOffset;
    isPaused = false;
  }
}

/**
 * @brief Checks if the AntiDelay instance is currently running.
 *
 * @return `true` if the instance is running, `false` otherwise.
 */
bool AntiDelay::isRunning()
{
  return !isPaused && millis() - previousMillis < timeInterval;
}