#ifndef AntiDelay_h
#define AntiDelay_h

#include "Arduino.h"

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

#endif