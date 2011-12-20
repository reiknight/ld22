#include "StartScene.h"
#include "Game.h"

StartScene::StartScene()
{
  background = 0;
  button = 0;
  
  reload();
}

StartScene::~StartScene()
{
  clean();                         
}

void StartScene::reload()
{
  background = new Sprite("assets/title.xml"); 
  button = new Button("assets/play.xml");
}

void StartScene::clean()
{
  if(background != 0)
    delete background;     
  if(button != 0)
    delete button;
}

void StartScene::render()
{
  background->render();     
  button->render();
}

void StartScene::update(float dt)
{
  background->update(dt);     
  button->update(dt);
  if(button->isPressed())
  {
    Game::getInstance()->getSceneManager()->setActive(MAIN_SCENE);                       
  }
}
