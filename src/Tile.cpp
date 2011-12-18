#include "Tile.h"
#include "Game.h"

Tile::Tile(const char *sprite_file, int resource_id) : Sprite((char *)sprite_file)
{
  resource = 0;
  if(resource_id != -1)
    resource = Game::getInstance()->getResourceManager()->getResource(resource_id);
}

Tile::~Tile()
{
             
}

Resource* Tile::getResource()
{
  return resource;         
}
