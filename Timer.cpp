#include "Timer.h"

Timer::Timer()
{
  current_time = glutGet(GLUT_ELAPSED_TIME);
  frames_per_second = 0;       
}

Timer::~Timer()
{
               
}

float Timer::tick()
{
  float dt, now;
  
  now = glutGet(GLUT_ELAPSED_TIME);
  dt = now - current_time;
  current_time = now;
  
	frames_per_second = 1000/dt;
	
  return dt;
}      

float Timer::getCurrentTime()
{
  return current_time;
}

char* Timer::getFPS()
{
  char *str = new char[50];
  sprintf(str,"FPS: %4.2f",frames_per_second);
  return str;    
}
