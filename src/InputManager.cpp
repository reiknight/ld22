#include "InputManager.h"

InputManager::InputManager()
{
  for(int i = 0 ; i < 256; i++)   { keys[i] = false;                     }                            
  for(int i = 0 ; i < 3; i++)     { buttons[i] = Vector2D(-9000, 9000);  }
}

InputManager::~InputManager()
{

}

void InputManager::readKeyboard(unsigned char key, bool pressed)
{
  keys[key] = pressed;
}

void InputManager::readMouse(int button, int state, int x, int y)
{
  if(state == GLUT_DOWN)
    buttons[button] = Vector2D(x-GAME_WIDTH/2,y-GAME_HEIGHT/2);
  else
    buttons[button] = Vector2D(-9000, 9000);
}

bool InputManager::keyPressed(unsigned char key)
{
  return keys[key];
}

bool InputManager::clickedInside(int button, int x, int y, int w, int h)
{
  return buttons[button].x >= x && buttons[button].x <= x+w && buttons[button].y <= y && buttons[button].y >= y-h;
}
