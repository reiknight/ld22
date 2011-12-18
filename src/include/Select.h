#ifndef CLASS_SELECT_H
#define CLASS_SELECT_H

#include "Globals.h"
#include "Button.h"

class Select
{
  public:
    Select(int _x, int _y, int _w, int _h);
    ~Select();
    void render();
    void update(float dt);
    bool isFolded();
  private:
    int x;
    int y;
    int w;
    int h;
    int initial_h;
    bool folded;
    Button *button;
    vector<char *> options;
    int option_selected;
    float time;
};

#endif
