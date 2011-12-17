#ifndef TILE_CLASS_H
#define TILE_CLASS_H

#include "Globals.h"
#include "Sprite.h"

class Tile
{
  public:
    Tile(const char *_name, const char *sprite_file);
    ~Tile();
    void render(int x, int y);
  private:
    char *name;
    Sprite *sprite;
};

#endif
