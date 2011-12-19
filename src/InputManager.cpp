#include "InputManager.h"


InputManager::InputManager()
{
  for(int i = 0 ; i < 256; i++)   { keys[i] = false; }                            
}

InputManager::~InputManager()
{
  delete[] buttons;
}

void InputManager::readKeyboard(unsigned char key, bool pressed)
{
  if(pressed)
    last_key_pressed = key;
    
  keys[key] = pressed;
}

void InputManager::readMouse(int button, int state, int x, int y)
{  
  buttons[button] = MouseEvent(state, x, y);
}

bool InputManager::keyPressed(unsigned char key)
{
  return keys[key];
}

bool InputManager::clickedInside(int button, int x, int y, int w, int h)
{
  if(buttons[button].isPressed()) {
    return buttons[button].getPosition().x >= x && buttons[button].getPosition().x <= x+w && -1*buttons[button].getPosition().y <= y && -1*buttons[button].getPosition().y >= y-h;
  }
  return false;
}

MouseEvent InputManager::getLastClick(int button)
{
  return buttons[button];
}

unsigned char InputManager::getLastKeyPressed()
{
  return last_key_pressed;
}
