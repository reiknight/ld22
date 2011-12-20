#include "MainScene.h"
#include "Game.h"

MainScene::MainScene()
{
  map = 0;
  time = 0;
  turn_time = 5000;
  picking_time = 0;
  
  reload();
}

MainScene::~MainScene()
{
  clean();
}

void MainScene::reload()
{
  clean();
  
  map = new TileMap("assets/map.xml");              
}

void MainScene::clean()
{
  if(map != 0)
    delete map;  
}
    
void MainScene::render()
{
  char time_left[50];
  
  map->render();
  Game::getInstance()->getPlayer()->render();
  
  sprintf(time_left, "%2.f seconds", ceil((turn_time/1000) - (time/1000)));
  glColor3f(1.0f,1.0f,1.0f);
  renderBitmapString(500,100,GLUT_BITMAP_HELVETICA_12,time_left);
}

void MainScene::update(float dt)
{
  int distance;
  Tile *tile;
  
  map->update(dt);
  Game::getInstance()->getPlayer()->update(dt);
  
  if(!picking)
  {
    time += dt;
    if(time > turn_time)
    {
      time = 0;
      Game::getInstance()->getSceneManager()->setActive(MANAGE_SCENE);
    }
  }
  else
  {
    picking_time += dt;
    if(picking_time > 500)
    {;
      tile = map->checkClick();
      if(tile != 0 && tile->getResource() != 0)
      {
        picking = false;
        picking_time = 0;
        distance = floor(Game::getInstance()->getPlayer()->euclidean(tile)/100);
        ((ManageScene*)Game::getInstance()->getSceneManager()->getScene(MAIN_SCENE))->setDistance(distance);
        Game::getInstance()->getSceneManager()->setActive(MANAGE_SCENE);
      }
    }
  }
}

void MainScene::pickResource()
{
  picking = true;
}
