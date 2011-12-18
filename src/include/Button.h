#ifndef CLASS_BUTTON_H
#define CLASS_BUTTON_H

#include "Globals.h"
#include "Sprite.h"

class Button : public Sprite
{
  public:
    Button(char *sprite_file);
    ~Button();
    void update(float dt);
    bool isPressed();
  private:
    bool pressed;
    float time;
};

#endif
