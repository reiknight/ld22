#ifndef CLASS_TILE_H
#define CLASS_TILE_H

#include "Globals.h"
#include "Sprite.h"

class Tile
{
  public:
    Tile(const char *_name, const char *sprite_file);
    ~Tile();
    void render(int x, int y);
    void update(float dt);
  private:
    char *name;
    Sprite *sprite;
};

#endif
