#ifndef CLASS_TIMER_H
#define CLASS_TIMER_H

#include "Globals.h"

class Timer
{
  public:
    Timer();
    ~Timer();
    float tick();
    float getCurrentTime();
    char* getFPS();
  private:
    float current_time;
    float frames_per_second;
};

#endif
