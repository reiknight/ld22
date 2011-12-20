#include "ManageScene.h"
#include "Game.h"

ManageScene::ManageScene()
{
  button = 0;
  picking = -1;
  distance = 0;
  
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
  Button *crosshair;
  
  clean();
   
  button = new Button("assets/button.xml");
  
  for(int i = 0; i < 10; i++)
  {
    select = new Select(75, -20-35*i, 300, 30);
    selects.push_back(select);
    
    text_input = new TextInput(400, -20-35*i, 75, 30, "1");
    text_inputs.push_back(text_input);
    
    crosshair = new Button("assets/crosshair.xml");
    crosshairs.push_back(crosshair);
    
    distances.push_back(-1);
  }
}

void ManageScene::clean()
{
  if(button != 0)
    delete button; 
    
  selects.clear();
  text_inputs.clear();
  crosshairs.clear();
}
    
void ManageScene::render()
{
  int last_render = -1;
  Resource *resource;
  
  button->render();
  
  for(int i = 0; i < 10; i++)
  {
    if(selects[i]->isFolded())
      last_render = i;
    else {
      selects[i]->render();
      resource = Game::getInstance()->getResourceManager()->getResource(selects[i]->getOptionSelected());
      if(resource->isPrime()) {
        crosshairs[i]->render(500, -20-35*i);    
        glPushMatrix();
        glTranslatef(0,GAME_HEIGHT,0);
        glColor3f(1.0f,1.0f,1.0f);
        if(distances[i] == -1)
      	  renderBitmapString(540,-40-35*i,GLUT_BITMAP_HELVETICA_12,"Not selected");
     	  else
     	  {
          char value[50];
          sprintf(value, "%d hours", distances[i]);
     	    renderBitmapString(540,-40-35*i,GLUT_BITMAP_HELVETICA_12,value);
        }
        glPopMatrix();                    
      }
    }
      
    text_inputs[i]->render();
  }
  if(last_render != -1)
    selects[last_render]->render(); 
       
  glColor3f(1,1,1);
	for(int i = 0; i < 10; i++)
	{
    Game::getInstance()->getPlayer()->getWorker(i)->render(20, -20-35*i);
  }
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
    if(Game::getInstance()->getPlayer()->endTurn(selects, text_inputs)) 
    { 
      Game::getInstance()->getSceneManager()->setActive(END_SCENE);
    }
    else
    {
      Game::getInstance()->getSceneManager()->setActive(MAIN_SCENE);
    }
  }
  
  if(picking >= 0)
  {
    cout << "PICK: " << distance << endl;
    distances[picking] = distance;
    picking = -1;
  }

  for(int i = 0; i < 10; i++)
  {
    crosshairs[i]->update(dt);
    if(crosshairs[i]->isPressed())
    {
      picking = i;
      ((MainScene*)Game::getInstance()->getSceneManager()->getScene(MAIN_SCENE))->pickResource();
      Game::getInstance()->getSceneManager()->setActive(MAIN_SCENE);
    }
  }
}

void ManageScene::setDistance(int _distance)
{
  cout << "SET: " << _distance << endl;
  distance = _distance;
}
