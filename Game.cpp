#include "Game.h"
 
void renderBitmapString(float x, float y, void *font, char *string);

Game::Game()
{

}

Game::~Game()
{

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

  glBegin(GL_QUADS);
  glVertex2f(50.0f, 0.0f);
  glVertex2f(50.0f, 50.0f);
  glVertex2f(0.0f, 50.0f);
  glVertex2f(0.0f, 0.0f);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(200.0f, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(0.0f, 200.0f);
  glEnd();
  
	glColor3f(1.0f,1.0f,1.0f);
	renderBitmapString(250,250,GLUT_BITMAP_HELVETICA_12,timer.getFPS());

  glutSwapBuffers();
}

void Game::update(float dt)
{

}

void Game::readKeyboard(char key, bool pressed)
{
  if(key == 27) {
    exit(0);
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
