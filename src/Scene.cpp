#include "Scene.h"

Scene::Scene()
{
  map = new TileMap("assets/map.xml");              
  sprite = new Sprite("assets/turtle.xml");
}

Scene::~Scene()
{
  delete map;  
  delete sprite;            
}

void Scene::render()
{
  map->render();
  sprite->render();
  
  drawAxis();
}

void Scene::update(float dt)
{
  map->update(dt);
  sprite->update(dt);
}
