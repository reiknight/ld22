#include "MouseEvent.h"

MouseEvent::MouseEvent()
{
  pressed = false;
  position = Vector2D();
}

MouseEvent::MouseEvent(int _pressed, int x, int y)
{
  pressed = (_pressed == GLUT_DOWN);
  position = Vector2D(x,y);
}

MouseEvent::~MouseEvent()
{
                         
}

Vector2D MouseEvent::getPosition()
{
  return position;
}

bool MouseEvent::isPressed()
{
  return pressed;    
}
