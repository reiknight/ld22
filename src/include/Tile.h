#ifndef TILE_CLASS_H
#define TILE_CLASS_H

#include "Globals.h"
#include "Sprite.h"

class Tile
{
  public:
    Tile(char *_name, char *sprite_file);
    ~Tile();
  private:
    char *name;
    Sprite *sprite;
};

#endif
