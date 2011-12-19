#ifndef CLASS_TEXT_INPUT_H
#define CLASS_TEXT_INPUT_H

#include "Globals.h"

class TextInput
{
  public:
    TextInput(int _x, int _y, int _w, int _h, char *_value);
    ~TextInput();
    char* getValue();
    void render();
    void update(float dt);
    bool isEditing();
  private:
    char *value;
    bool editing;
    int x;
    int y;
    int w;
    int h;
};

#endif
