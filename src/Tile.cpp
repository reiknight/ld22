#include "Tile.h"

Tile::Tile(const char *_name, const char *sprite_file) : Sprite((char *)sprite_file)
{
  name = (char *)_name;
}

Tile::~Tile()
{
}
