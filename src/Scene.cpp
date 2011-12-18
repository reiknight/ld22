#include "Scene.h"
#include "Game.h"

Scene::Scene()
{
  map = 0;
  player = 0;
  button = 0;
  end_turn = false;
  time = 0;
  turn_time = 10000; // 10s
  
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
  player = new Player("assets/player.xml"); 
  button = new Button("assets/button.xml");
}

void Scene::clean()
{
  if(map != 0)
    delete map;  
  
  if(player != 0)
    delete player;
    
  if(button != 0)
    delete button; 
}
    
void Scene::render()
{
  if(!end_turn)
  {
    map->render();
    player->render();
    
    char time_left[50];
    sprintf(time_left, "%2.f seconds", ceil((turn_time/1000) - (time/1000)));
    glColor3f(1.0f,1.0f,1.0f);
  	renderBitmapString(500,100,GLUT_BITMAP_HELVETICA_12,time_left);
  }
  else
  {
    button->render();
    
    glPushMatrix();
    glTranslatef(0,GAME_HEIGHT,0);
    glColor3f(1.0f,1.0f,1.0f);
  	for(int i = 0; i < 10; i++)
  	{
     	renderBitmapString(10,-i*30,GLUT_BITMAP_HELVETICA_12,"worker");
    }
    glPopMatrix();
  }
}

void Scene::update(float dt)
{
  time += dt;
  
  if(!end_turn)
  {
    map->update(dt);
    player->update(dt);
    
    if(time > turn_time)
      end_turn = true;
  }
  else
  {
    button->update(dt);
    if(button->isPressed())
    {
      time = 0;
      end_turn = false;
    }
  }
}
