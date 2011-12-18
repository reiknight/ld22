#ifndef CLASS_TILE_H
#define CLASS_TILE_H

#include "Globals.h"
#include "Sprite.h"

class Tile : public Sprite
{
  public:
    Tile(const char *_name, const char *sprite_file);
    ~Tile();
  private:
    char *name;
};

#endif
