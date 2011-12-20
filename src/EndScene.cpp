#include "EndScene.h"
#include "Game.h"

EndScene::EndScene()
{
  background = 0;
  button = 0;
  
  reload();              
}

EndScene::~EndScene()
{
  clean();                         
}

void EndScene::reload()
{
  clean();
  
  background = new Sprite("assets/gameover.xml"); 
  button = new Button("assets/play_again.xml");
}

void EndScene::clean()
{
  if(background != 0)
    delete background;     
  if(button != 0)
    delete button;
}

void EndScene::render()
{
  background->render();     
  button->render();   
}

void EndScene::update(float dt)
{
  background->update(dt);     
  button->update(dt);
  if(button->isPressed())
  {
    Game::getInstance()->getSceneManager()->getScene(MAIN_SCENE)->reload();
    Game::getInstance()->getSceneManager()->getScene(MANAGE_SCENE)->reload();
    Game::getInstance()->getSceneManager()->setActive(MAIN_SCENE);                       
  } 
}
