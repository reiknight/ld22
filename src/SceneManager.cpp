#include "SceneManager.h"

SceneManager::SceneManager()
{
  scenes = vector<Scene*> (100);
  active = -1;                      
}

SceneManager::~SceneManager()
{
  clean();   
}

void SceneManager::reload()
{
  clean();
  loadScenes();   
}

void SceneManager::clean()
{
  scenes.clear();       
}
    
void SceneManager::render()
{
  scenes[active]->render();     
}

void SceneManager::update(float dt)
{
  scenes[active]->update(dt); 
}

void SceneManager::setActive(int _active)
{
  active = _active;     
}

void SceneManager::loadScenes()
{
  scenes[MAIN_SCENE] = new MainScene();
  scenes[MANAGE_SCENE] = new ManageScene();
  scenes[START_SCENE] = new StartScene();
  scenes[END_SCENE] = new EndScene();
}

Scene* SceneManager::getScene(int id)
{
  return scenes[id];
}
