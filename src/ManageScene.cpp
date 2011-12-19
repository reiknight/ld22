#include "ManageScene.h"
#include "Game.h"

ManageScene::ManageScene()
{
  button = 0;
  
  reload();
}

ManageScene::~ManageScene()
{
  clean();
}

void ManageScene::reload()
{
  Select *select;
  TextInput *text_input;
  
  clean();
   
  button = new Button("assets/button.xml");
  
  for(int i = 0; i < 10; i++)
  {
    select = new Select(75, -20-35*i, 300, 30);
    selects.push_back(select);
    
    text_input = new TextInput(400, -20-35*i, 75, 30, "1");
    text_inputs.push_back(text_input);
  }
}

void ManageScene::clean()
{
  if(button != 0)
    delete button; 
    
  selects.clear();
  text_inputs.clear();
}
    
void ManageScene::render()
{
  int last_render = -1;
  
  button->render();
  
  for(int i = 0; i < 10; i++)
  {
    if(selects[i]->isFolded())
      last_render = i;
    else
      selects[i]->render();
      
    text_inputs[i]->render();
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

void ManageScene::update(float dt)
{
  int update_folded = -1;
  int update_editing = -1;
    
  button->update(dt);
  
  for(int i = 0; i < 10; i++)
  {
    if(selects[i]->isFolded())
      update_folded = i;
      
    if(text_inputs[i]->isEditing())
      update_editing = i;
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
  
  if(update_editing == -1)
  {
    for(int i = 0; i < 10; i++)
    {
      text_inputs[i]->update(dt);
    }
  }
  else
  {
    text_inputs[update_editing]->update(dt);  
  }
      
  if(button->isPressed())
  {
    if(Game::getInstance()->getPlayer()->endTurn(selects, text_inputs)) { exit(0); } //se acaba el juego
    Game::getInstance()->getSceneManager()->setActive(MAIN_SCENE);
  }
}
