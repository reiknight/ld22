#ifndef CLASS_MAP_H
#define CLASS_MAP_H

#include "Globals.h"
#include "Sprite.h"
#include "Tile.h"

class Map
{
  public:
    Map(char *filename);
    ~Map();
    void reload();
    void clean();
    void render();
    void update(float dt);
  private:
    char *map_file;
    vector<Tile*> tiles;
};

#endif
