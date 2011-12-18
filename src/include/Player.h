#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include "Globals.h"
#include "Sprite.h"
#include "Worker.h"

class Player : public Sprite {
      public:
              Player(char *sprite_file);
              ~Player();
              void incMoney(int inc);
              void incHappiness(int inc);
      private:
              long int money;
              int n_workers;
              Worker* workers;
              float happiness;
};

#endif
