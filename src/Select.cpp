#include "Select.h"
#include "Game.h"
#include "MouseEvent.h"

Select::Select(int _x, int _y, int _w, int _h)
{
  initial_h = _h;

  x = _x;
  y = _y;
  w = _w;
  h = _h;
  folded = false;
  button = new Button("assets/select.xml");     
  
  options.push_back("Option 1");     
  options.push_back("Option 2");
  options.push_back("Option 3");
  options.push_back("Option 4");      
  options.push_back("Option 5");
  options.push_back("Option 6");
  options.push_back("Option 7");
  options.push_back("Option 8");
  
  option_selected = 0;
  time = 0;
}

Select::~Select()
{
  delete button;                
}

void Select::render()
{
  if(!folded)
  {
    h = initial_h;
  }
  else
  {
    h = initial_h+300;
  }
  
  glPushMatrix();
  glTranslatef(0,GAME_HEIGHT,0);
  glColor3f(1,1,1);
  glBegin(GL_QUADS);
    glVertex2f(x, y-h);
    glVertex2f(x+w, y-h);
    glVertex2f(x+w, y);
    glVertex2f(x, y);
  glEnd();
  glPopMatrix();

  glColor3f(1,1,1);
  button->render(x+w - 40, y-initial_h + 35);

  glPushMatrix();
  glTranslatef(0,GAME_HEIGHT,0);
  glColor3f(1,0,0);
  if(!folded)
  {
  	renderBitmapString(x+20,y-20,GLUT_BITMAP_HELVETICA_12,options[option_selected]);               
  }
  else
  {
    for(int i = 0; i < options.size(); i++)  
    	renderBitmapString(x+20,y-20-i*35,GLUT_BITMAP_HELVETICA_12,options[i]);   
  }
  glPopMatrix();
}

void Select::update(float dt)
{     
  time += dt;
  
  if(folded && time > 200)
  {
    if(Game::getInstance()->getInputManager()->clickedInside(GLUT_LEFT_BUTTON, x, y, w, h))
    {
      MouseEvent event = Game::getInstance()->getInputManager()->getLastClick(GLUT_LEFT_BUTTON);
      option_selected = (event.getPosition().y-20) / 35;
      folded = false;
    }
  }  
    
  button->update(dt);
  if(button->isPressed())
  {
    folded = !folded; 
    time = 0;
  }
}
