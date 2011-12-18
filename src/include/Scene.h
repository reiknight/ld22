#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Globals.h"
#include "Player.h"
#include "TileMap.h"
#include "Button.h"

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
    Player *player;
    Button *button;
    bool end_turn;
    float time;
    float turn_time;
};

#endif
