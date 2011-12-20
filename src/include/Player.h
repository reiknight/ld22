#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include "Globals.h"
#include "Sprite.h"
#include "Worker.h"
#include "Select.h"
#include "TextInput.h"

class Player : public Sprite {
      public:
              Player(char *sprite_file);
              ~Player();
              void incMoney(int inc);
              void incHappiness(int inc);
              bool endTurn(vector<Select *> selects, vector<TextInput *> text_inputs);
              Worker* getWorker(int i);
      private:
              long int money;
              int n_workers;
              Worker* workers;
              float happiness;
};

#endif
