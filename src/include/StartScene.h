#ifndef CLASS_START_SCENE_H
#define CLASS_START_SCENE_H

#include "Globals.h"
#include "Scene.h"

class StartScene : public Scene
{
  public:
    StartScene();
    ~StartScene();
    void reload();
    void clean();
    void render();
    void update(float dt);
  private:
    Sprite *background;
    Button *button;

};

#endif
