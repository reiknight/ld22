#include "InputManager.h"

InputManager::InputManager()
{
                            
}

InputManager::~InputManager()
{

}

void InputManager::readKeyboard(unsigned char key, bool pressed)
{
  keys[key] = pressed;
  
  if(keys[27])
    exit(0);
}

void InputManager::readMouse(int button, int state, int x, int y)
{
  if(state == GLUT_DOWN)
    buttons[button] = Vector2D(x,y);
}
