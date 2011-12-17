#include "Tile.h"

Tile::Tile(char *_name, char *sprite_file)
{
  name = _name;
  sprite = new Sprite(sprite_file);
}

Tile::~Tile()
{
  delete sprite;
}
