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
  
  options.push_back(new Button("assets/wood_button.xml"));     
  options.push_back(new Button("assets/metal_button.xml"));
  options.push_back(new Button("assets/water_button.xml"));
  options.push_back(new Button("assets/oil_button.xml"));
  options.push_back(new Button("assets/wool_button.xml"));
  
  option_selected = 0;
  time = 0;
}

Select::~Select()
{
  options.clear();
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
    h = initial_h+100;
  }
  
  glPushMatrix();
  glTranslatef(0,GAME_HEIGHT,0);
  if(!folded)
    glColor3f(0.7,0.7,0.7);
  else
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

  options[option_selected]->render(x, y);
  if(folded)
  {
    int pos_x = x;
    int pos_y = y;
    
    for(int i = 0; i < options.size(); i++)
    {
      if((i%4)) {
        pos_x += 75;
      }
      else
      {
        pos_y -= 35;
        pos_x = x;
      }
      options[i]->render(pos_x,pos_y);
    }
  }
}

void Select::update(float dt)
{     
  time += dt;
  
  if(folded && time > 200)
  {
    for(int i = 0; i < options.size(); i++)
    {
      options[i]->update(dt);
      if(options[i]->isPressed())
      {
        option_selected = i;
        folded = false;
      }
    }
  }  
    
  button->update(dt);
  if(button->isPressed())
  {
    folded = !folded; 
    time = 0;
  }
}

bool Select::isFolded()
{
  return folded;  
}

int Select::getOptionSelected() {
    return option_selected;
}
