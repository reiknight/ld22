#include "Game.h"
 
void renderBitmapString(float x, float y, void *font, char *string);

Game::Game()
{
  sprite = new Sprite("assets/turtle.xml");
  map = new Map("assets/map.xml");
}

Game::~Game()
{
  delete sprite;
}

void Game::loop()
{
  float dt;
  
  dt = timer.tick();
  update(dt);
  render();
}

void Game::render()
{
  int x,y;
  char* fps = new char[30];
  
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glColor4f(1.0f,1.0f,1.0f,1.0f);

  map->render();
  sprite->render();
    
	glColor3f(1.0f,1.0f,1.0f);
	renderBitmapString(450,450,GLUT_BITMAP_HELVETICA_12,timer.getFPS());

  glutSwapBuffers();
}

void Game::update(float dt)
{
  map->update(dt);
  sprite->update(dt);
}

void Game::readKeyboard(char key, bool pressed)
{
  if(key == GLUT_KEY_F1)
  {
    sprite->reload();
  } else {
    if(key == 27) {
      exit(0);
    }     
  }
}

void renderBitmapString(float x, float y, void *font, char *string)
{
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}
