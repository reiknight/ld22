#ifndef CLASS_INPUT_MANAGER_H
#define CLASS_INPUT_MANAGER_H

#include "Globals.h"
#include "Vector2D.h"

class InputManager
{
  public: 
    InputManager();
    ~InputManager();
    void readKeyboard(unsigned char key, bool pressed);
    void readMouse(int button, int state, int x, int y);
    bool keyPressed(unsigned char key);
    bool clickedInside(int button, int x, int y, int w, int h);
  private:
    unsigned char keys[256];
    Vector2D buttons[3];
};

#endif