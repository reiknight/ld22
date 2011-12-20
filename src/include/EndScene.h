#ifndef CLASS_END_SCENE_H
#define CLASS_END_SCENE_H

#include "Globals.h"
#include "Scene.h"

class EndScene : public Scene
{
  public:
    EndScene();
    ~EndScene();
    void reload();
    void clean();
    void render();
    void update(float dt);
  private:
    Sprite *background;
    Button *button;

};

#endif
