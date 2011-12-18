#ifndef CLASS_SPRITE_H
#define CLASS_SPRITE_H

#include "Globals.h"
#include "Texture.h"

class Sprite
{
  public:
    Sprite(char *filename);
    ~Sprite();
    void reload();
    void clean();
    void update(float dt);
    void render();
    void render(int _x, int _y);
    float distance(Sprite p);
  private:
    char *sprite_file;
    int x;
    int y;
    Texture *texture; 
    int frames;
    int current_frame;
    float animation_time;
    float counter;
    float frame_width;
    float offset_x;
    vector<int> animation;
};

#endif
