#include "Button.h"
#include "Game.h"

Button::Button(char *sprite_file) : Sprite(sprite_file)
{
  pressed = false;
  time = 0;          
}

Button::~Button()
{
                 
}

void Button::update(float dt)
{
  Sprite::update(dt);
      
  time += dt;
  if(time > 150)
  {
    pressed = Game::getInstance()->getInputManager()->clickedInside(GLUT_LEFT_BUTTON, x, y, texture->getWidth(), texture->getHeight());
    time = 0;
  }
}

bool Button::isPressed()
{
  if(pressed)
  {
    pressed = false;
    return true;    
  }
  return false;
}

