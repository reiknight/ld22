#ifndef CLASS_MOUSE_EVENT_H
#define CLASS_MOUSE_EVENT_H

#include "Globals.h"
#include "Vector2D.h"

class MouseEvent
{
  public:
    MouseEvent();
    MouseEvent(int pressed, int x, int y);
    ~MouseEvent();
    Vector2D getPosition();
    bool isPressed();
  private:
    Vector2D position;    
    bool pressed;
};

#endif
