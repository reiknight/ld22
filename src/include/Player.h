#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include "Globals.h"

class Player {
      public:
              Player();
              ~Player();
              void incMoney(int inc);
              void incHappiness(int inc);
      private:
              long int money;
              int workers;
              float happiness;
};

#endif
