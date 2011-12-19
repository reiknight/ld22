#include "TextInput.h"
#include "Game.h"

TextInput::TextInput(int _x, int _y, int _w, int _h, char *_value)
{
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  value = _value;
  editing = false;
}

TextInput::~TextInput()
{
                       
}

char* TextInput::getValue()
{
  return value;     
}

void TextInput::render()
{
  glPushMatrix();
  glTranslatef(0,GAME_HEIGHT,0);
  if(editing)
    glColor3f(1,1,1);
  else
    glColor3f(0.7,0.7,0.7);
  glBegin(GL_QUADS);
    glVertex2f(x, y-h);
    glVertex2f(x+w, y-h);
    glVertex2f(x+w, y);
    glVertex2f(x, y);
  glEnd();
  
  glColor3f(0,0,0);
  renderBitmapString(x+25,y-20,GLUT_BITMAP_HELVETICA_12,value);
  
  glPopMatrix();

}

void TextInput::update(float dt)
{
  if(editing)
  {
    if(Game::getInstance()->getInputManager()->keyPressed(13))
    {
      editing = false;
    }
    
    char *myString = new char[50]; // have enough characters allocated
    sprintf(myString, "%d",Game::getInstance()->getInputManager()->getLastKeyPressed() ); // this will get that uchar as numerical in the string.
    
    int n;
    sscanf(myString, "%d", &n);
    n -= 48;
    
    if(n >= 0 && n <=8)
    {
      value = new char[50];
      sprintf(value, "%d", n);
    }
  }
  else
  {
    if(Game::getInstance()->getInputManager()->clickedInside(GLUT_LEFT_BUTTON, x, y, w, h))
    {
      editing = true;
    }
  }
}

bool TextInput::isEditing()
{
  return editing;
}
