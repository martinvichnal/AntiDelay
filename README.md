# AntiDelay

![](https://img.shields.io/github/v/release/martinvichnal/AntiDelay)
![](https://img.shields.io/github/last-commit/martinvichnal/AntiDelay)
![](https://img.shields.io/github/issues/martinvichnal/AntiDelay)

---

## Overview

The `AntiDelay` library provides a non-blocking delay functionality for Arduino. It allows you to delay a function or a section of code without interrupting the microcontroller's code flow. This is particularly useful in applications where you need to perform multiple tasks concurrently.

-   _Feel free to **improve, use or fork** this repository in your own projects :)_
-   _For any bugs or improvements feel free to make an [issue](https://github.com/martinvichnal/AntiDelay/issues) or make a [pull request](https://github.com/martinvichnal/AntiDelay/pulls)_

---

# Table of Contents

-   [AntiDelay](#antidelay)
    -   [Overview](#overview)
-   [Table of Contents](#table-of-contents)
-   [Class Definition](#class-definition)
-   [Methods](#methods)
    -   [AntiDelay(unsigned long interval)](#antidelayunsigned-long-interval)
    -   [operator bool()](#operator-bool)
    -   [reset()](#reset)
    -   [setInterval(unsigned long interval)](#setintervalunsigned-long-interval)
    -   [pause()](#pause)
    -   [resume()](#resume)
    -   [isRunning()](#isrunning)
-   [Use Cases](#use-cases)
    -   [Blinking an LED without blocking](#blinking-an-led-without-blocking)
    -   [Pausing and resuming a delay](#pausing-and-resuming-a-delay)
    -   [Changing the delay interval](#changing-the-delay-interval)

---

# Class Definition

```cpp
class AntiDelay
{
  public:
    AntiDelay(unsigned long interval);
    operator bool();
    void reset();
    void setInterval(unsigned long interval);
    void pause();
    void resume();
    bool isRunning();

  private:
    unsigned long timeInterval;
    unsigned long previousMillis;
    bool isPaused;
    unsigned long pauseOffset;
};

```

# Methods

## AntiDelay(unsigned long interval)

The constructor for the AntiDelay class. It takes one parameter: the delay interval in milliseconds.

## operator bool()

This operator allows an AntiDelay object to be used in a conditional statement. It returns true if the delay interval has passed since the last time it returned true, and false otherwise.

## reset()

This method resets the delay timer to the current time.

## setInterval(unsigned long interval)

This method changes the delay interval. It takes one parameter: the new delay interval in milliseconds.

## pause()

This method pauses the delay timer. While the timer is paused, the operator bool() method will always return false.

## resume()

This method resumes the delay timer if it was previously paused. The timer will pick up where it left off.

## isRunning()

This method returns true if the delay timer is currently running (i.e., the delay interval has not yet passed or the timer is not paused), and false otherwise.

# Use Cases

## Blinking an LED without blocking

You can use the AntiDelay library to blink an LED at a regular interval without blocking the rest of your code. This allows your Arduino to perform other tasks at the same time.

```cpp
#include "AntiDelay.h"

AntiDelay blinkDelay(1000); // 1 second delay

void loop() {
  if (blinkDelay) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle the LED
  }
  // Other code here will run concurrently with the LED blinking
}

```

## Pausing and resuming a delay

You can pause and resume a delay using the pause() and resume() methods. This is useful in situations where you need to temporarily stop a recurring action.

```cpp
#include "AntiDelay.h"

AntiDelay actionDelay(1000); // 1 second delay

void loop() {
  if (actionDelay) {
    // Perform some action
  }
  if (someCondition) {
    actionDelay.pause();
  }
  if (someOtherCondition) {
    actionDelay.resume();
  }
}

```

## Changing the delay interval

You can change the delay interval on the fly using the setInterval() method. This is useful in situations where the delay needs to be adjusted based on some condition.

```cpp
#include "AntiDelay.h"

AntiDelay variableDelay(1000); // 1 second delay

void loop() {
  if (variableDelay) {
    // Perform some action
  }
  if (someCondition) {
    variableDelay.setInterval(2000); // Change the delay to 2 seconds
  }
}

```
