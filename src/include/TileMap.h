#ifndef CLASS_TILE_MAP_H
#define CLASS_TILE_MAP_H

#include "Globals.h"
#include "Sprite.h"
#include "Tile.h"
#include "Vector2D.h"

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
    int rows;
    int cols;
    int tile_width;
    int tile_height;
    char *map_file;
    vector<Tile*> tiles;
    int **tileset;
    Tile* checkClick();
};

#endif
