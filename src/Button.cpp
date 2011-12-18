#include "Button.h"
#include "Game.h"

Button::Button(char *sprite_file) : Sprite(sprite_file)
{
  pressed = false;          
}

Button::~Button()
{
                 
}

void Button::update(float dt)
{
  Sprite::update(dt);
  pressed = Game::getInstance()->getInputManager()->clickedInside(GLUT_LEFT_BUTTON, x, y, texture->getWidth(), texture->getHeight());
}

bool Button::isPressed()
{
  return pressed;    
}

