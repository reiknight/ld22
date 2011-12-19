#include "Game.h"

Game::Game()
{
  tm = 0;          
  im = 0;
  rm = 0;
  sm = 0;
  player = 0;
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
  
  sm = new SceneManager();
  sm->loadScenes();
  sm->setActive(MAIN_SCENE);
  
  player = new Player("assets/player.xml"); 
}

void Game::clean()
{
  if(tm != 0)
    delete tm;
  if(im != 0)
    delete im;
  if(rm != 0)    
    delete rm;
  if(sm != 0)
    delete sm;
  if(player != 0)
    delete player;
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
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glColor4f(1.0f,1.0f,1.0f,1.0f);

  sm->render();

  glutSwapBuffers();
}

void Game::update(float dt)
{
  if(im->keyPressed(27))
    exit(0);

  if(im->keyPressed(GLUT_KEY_F1))
    sm->reload();
    
 sm->update(dt);
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

InputManager* Game::getInputManager()
{
  return im;
}

ResourceManager* Game::getResourceManager()
{
  return rm;
}

SceneManager* Game::getSceneManager()
{
  return sm;              
}

Player* Game::getPlayer()
{
  return player;
}

