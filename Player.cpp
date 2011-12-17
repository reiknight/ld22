#include "Player.h"

Player::Player() {
   money = 0; //No score in the beginning
   happiness = 0; //No happiness
   workers = 10;
}

Player::~Player() {}

void Player::incMoney(int inc) {
   money += inc;
}

void Player::incHappiness(int inc) {
   happiness += inc;
}
