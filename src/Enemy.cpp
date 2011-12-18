#include "Enemy.h"

Enemy::Enemy(const char *sprite_file) {
               science = 0; //No science
               sprite = new Sprite((char *)sprite_file);
}

Enemy::~Enemy() {
   delete sprite;
}
