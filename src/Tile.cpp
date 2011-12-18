#include "Tile.h"

Tile::Tile(const char *_name, const char *sprite_file)
{
  name = (char *)_name;
  sprite = new Sprite((char *)sprite_file);
}

Tile::~Tile()
{
  delete sprite;
}

void Tile::render(int x, int y)
{
  sprite->render(x,y);
}

void Tile::update(float dt)
{
  sprite->update(dt);
}
