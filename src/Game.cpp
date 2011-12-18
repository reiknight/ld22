#include "Game.h"

Game::Game()
{
          
}

Game::~Game()
{
  clean();
}

void Game::reload()
{
  clean();
  
  tm = new TextureManager();
  tm->loadTextures("assets/textures.xml");
  
  im = new InputManager();
  
  rm = new ResourceManager();
  rm->loadResources("assets/resources.xml");
  
  scene = new Scene();
}

void Game::clean()
{
  delete tm;
  delete im;
  delete rm;
  delete scene;
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

  scene->render();
  
	glColor3f(1.0f,1.0f,1.0f);
	renderBitmapString(450,450,GLUT_BITMAP_HELVETICA_12,timer.getFPS());

  glutSwapBuffers();
}

void Game::update(float dt)
{
  if(im->keyPressed(27))
    exit(0);
    
  if(im->clickedInside(GLUT_LEFT_BUTTON, -100, 100, 200, 200))
    exit(0);
    
  scene->update(dt);
}

void Game::readMouse(int button, int state, int x, int y)
{
  im->readMouse(button, state, x, y);     
}

void Game::readKeyboard(unsigned char key, bool pressed)
{
  im->readKeyboard(key, pressed);
}

TextureManager* Game::getTextureManager()
{
  return tm;
}

ResourceManager* Game::getResourceManager()
{
  return rm;
}
