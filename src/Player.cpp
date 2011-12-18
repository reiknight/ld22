#include "Player.h"

Player::Player(char *sprite_file) : Sprite(sprite_file) {
   money = 0; //No score in the beginning
   happiness = 0; //No happiness
   n_workers = 10;
   workers = new Worker[10];
}

Player::~Player() {
}

void Player::incMoney(int inc) {
   money += inc;
}

void Player::incHappiness(int inc) {
   happiness += inc;
}
