#ifndef CLASS_SPRITE_H
#define CLASS_SPRITE_H

#include "Globals.h"
#include "Texture.h"

class Sprite
{
  public:
    Sprite(int x, int y, char *filename, int frames, float animation_time, int animation[]);
    ~Sprite();
    void update(float dt);
    void render();
  private:
    int x;
    int y;
    Texture *texture; 
    int frames;
    int current_frame;
    float animation_time;
    float counter;
    float frame_width;
    float offset_x;
    int *animation;
};

#endif
