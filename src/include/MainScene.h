#ifndef CLASS_MAIN_SCENE_H
#define CLASS_MAIN_SCENE_H

#include "Globals.h"
#include "Scene.h"
#include "TileMap.h"
#include "Player.h"

class MainScene : public Scene
{
  public:
    MainScene();
    ~MainScene();
    void reload();
    void clean();
    void render();
    void update(float dt);
  private:
    TileMap *map;
    int time;
    int turn_time;  
};

#endif
