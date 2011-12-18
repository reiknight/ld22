#ifndef CLASS_ENEMY_H
#define CLASS_ENEMY_H

#include "Globals.h"
#include "Sprite.h"

class Enemy : public Sprite {
      public:
             Enemy();
             ~Enemy();
      private:
              long int science;
};

#endif
