#include "Scene.h"

Scene::Scene()
{
  map = 0;
  sprite = 0;
  
  reload();
}

Scene::~Scene()
{
  clean();
}

void Scene::reload()
{
  clean();
  
  map = new TileMap("assets/map.xml");              
  sprite = new Sprite("assets/turtle.xml");  
}

void Scene::clean()
{
  if(map != 0)
    delete map;  
  
  if(sprite != 0)
    delete sprite; 
}
    
void Scene::render()
{
  map->render();
  sprite->render();
  
  //drawAxis();
}

void Scene::update(float dt)
{
  map->update(dt);
  sprite->update(dt);
}
