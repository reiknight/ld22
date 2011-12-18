#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include "Globals.h"
#include "Sprite.h"

class Player {
      public:
              Player(const char *sprite_file);
              ~Player();
              void incMoney(int inc);
              void incHappiness(int inc);
              void render(int x, int y);
              void update(float dt);
      private:
              long int money;
              int workers;
              float happiness;
              Sprite *sprite;
};

#endif
