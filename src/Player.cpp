#include "Player.h"

Player::Player(const char *sprite_file) {
   money = 0; //No score in the beginning
   happiness = 0; //No happiness
   workers = 10;
   sprite = new Sprite((char *)sprite_file);
}

Player::~Player() {
   delete sprite;
}

void Player::incMoney(int inc) {
   money += inc;
}

void Player::incHappiness(int inc) {
   happiness += inc;
}

void Player::render(int x, int y)
{
  sprite->render(x,y);
}

void Player::update(float dt)
{
  sprite->update(dt);
}
