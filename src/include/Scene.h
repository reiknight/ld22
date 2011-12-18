#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Globals.h"
#include "Sprite.h"
#include "TileMap.h"

class Scene
{
  public:
    Scene();
    ~Scene();
    void reload();
    void clean();
    void render();
    void update(float dt);
  private:
    TileMap *map;  
    Sprite *sprite;
};

#endif
