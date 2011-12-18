#ifndef CLASS_TILE_H
#define CLASS_TILE_H

#include "Globals.h"
#include "Sprite.h"
#include "Resource.h"

class Tile : public Sprite
{
  public:
    Tile(const char *sprite_file, int resource_id);
    ~Tile();
    Resource* getResource();
  private:
    Resource *resource;
};

#endif
