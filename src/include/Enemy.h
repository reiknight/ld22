#ifndef CLASS_ENEMY_H
#define CLASS_ENEMY_H

#include "Globals.h"
#include "Sprite.h"

class Enemy {
      public:
             Enemy(const char *sprite_file);
             ~Enemy();
             void render(int x, int y);
             void update(float dt);
      private:
              long int science;
              Sprite *sprite;
};

#endif
