#include "MainScene.h"
#include "Game.h"

MainScene::MainScene()
{
  map = 0;
  time = 0;
  turn_time = 10000;
  
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
  time += dt;
  
  map->update(dt);
  Game::getInstance()->getPlayer()->update(dt);
    
  if(time > turn_time)
  {
    time = 0;
    Game::getInstance()->getSceneManager()->setActive(MANAGE_SCENE);
  }
}
