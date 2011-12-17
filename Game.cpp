#include "Game.h"

Game::Game()
{
  //sm = new SceneManager();
}

Game::~Game()
{
  //delete sm;
}

void Game::loop()
{
  render();
  update(0);
}

void Game::render()
{
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

  glutSwapBuffers();
  //sm->render();
}

void Game::update(float dt)
{
  //sm->update(dt);
}

void Game::readKeyboard(char key, bool pressed)
{
  if(key == 27) {
    exit(0);
  }     
}

//SceneManager* Game::getSceneManager()
//{
//  return sm;
//}
