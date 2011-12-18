#include "Scene.h"
#include "Game.h"

Scene::Scene()
{
  map = 0;
  player = 0;
  button = 0;
  end_turn = true;
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
  Select *select;
  clean();
  
  map = new TileMap("assets/map.xml");              
  player = new Player("assets/player.xml"); 
  button = new Button("assets/button.xml");
  
  for(int i = 0; i < 10; i++)
  {
    select = new Select(75, -20-35*i, 200, 30);
    selects.push_back(select);
  }
}

void Scene::clean()
{
  if(map != 0)
    delete map;  
  
  if(player != 0)
    delete player;
    
  if(button != 0)
    delete button; 
    
  selects.clear();
}
    
void Scene::render()
{
  int last_render = -1;
  
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
    
    for(int i = 0; i < 10; i++)
    {
      if(selects[i]->isFolded())
        last_render = i;
      else
        selects[i]->render();
    }
    if(last_render != -1)
      selects[last_render]->render();    
      
    glPushMatrix();
    glTranslatef(0,GAME_HEIGHT,0);
    glColor3f(1.0f,1.0f,1.0f);
  	for(int i = 0; i < 10; i++)
  	{
     	renderBitmapString(10,-i*40,GLUT_BITMAP_HELVETICA_12,"worker");
    }
    glPopMatrix();
  }
}

void Scene::update(float dt)
{
  int update_folded = -1;
  
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
    
    for(int i = 0; i < 10; i++)
    {
      if(selects[i]->isFolded())
        update_folded = i;
    }

    if(update_folded == -1)
    {
      for(int i = 0; i < 10; i++)
      {
        selects[i]->update(dt);
      }
    }
    else
    {
      selects[update_folded]->update(dt);  
    }
        
    if(button->isPressed())
    {
      time = 0;
      end_turn = false;
    }
  }
}
