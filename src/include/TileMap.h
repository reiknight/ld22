#ifndef CLASS_TILE_MAP_H
#define CLASS_TILE_MAP_H

#include "Globals.h"
#include "Sprite.h"
#include "Tile.h"

class TileMap
{
  public:
    TileMap(char *filename);
    ~TileMap();
    void reload();
    void clean();
    void render();
    void update(float dt);
  private:
    char *map_file;
    vector<Tile*> tiles;
};

#endif
