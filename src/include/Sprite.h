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
    virtual void update(float dt);
    void render();
    void render(int _x, int _y);
    float euclidean(Sprite *p); //Euclidean distance (d_2)
    int distance(Sprite *p); //Absolute distance (d_1)
    void setPosition(int _x, int _y);
    void setCurrentFrame(int i);
  protected:
    int x;
    int y;
    Texture *texture; 
  private:
    char *sprite_file;
    int frames;
    int current_frame;
    float animation_time;
    float counter;
    float frame_width;
    float offset_x;
    vector<int> animation;
};

#endif
