#ifndef CLASS_INPUT_MANAGER_H
#define CLASS_INPUT_MANAGER_H

#include "Globals.h"
#include "MouseEvent.h"

class InputManager
{
  public: 
    InputManager();
    ~InputManager();
    void readKeyboard(unsigned char key, bool pressed);
    void readMouse(int button, int state, int x, int y);
    bool keyPressed(unsigned char key);
    bool clickedInside(int button, int x, int y, int w, int h);
    MouseEvent getLastClick(int button);
    unsigned char getLastKeyPressed();
  private:
    unsigned char keys[256];
    MouseEvent buttons[3];
    unsigned char last_key_pressed;
    int mouse_time;
};

#endif
