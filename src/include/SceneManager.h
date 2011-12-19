#ifndef CLASS_SCENE_MANAGER_H
#define CLASS_SCENE_MANAGER_H

#include "Globals.h"
#include "Scene.h"
#include "MainScene.h"
#include "ManageScene.h"

#define MAIN_SCENE 0
#define MANAGE_SCENE 1

class SceneManager
{
  public:
    SceneManager();
    ~SceneManager();
    void reload();
    void clean();
    void addScene(int id, Scene *scene);
    void render();
    void update(float dt);
    void setActive(int _active);
    void loadScenes();
  private:
    vector<Scene*> scenes;  
    int active;
};

#endif
