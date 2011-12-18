#ifndef CLASS_WORKER_H
#define CLASS_WORKER_H

#include "Globals.h"
#include "Sprite.h"
#include "Resource.h"

class Worker : public Sprite {
      public:
             Worker();
             Worker(const char *sprite_file);
             Worker(signed int life, float happiness, const char *sprite_file);
             ~Worker();
             void changeLife(int inc);
             void changeHours(int h);
      private:
              signed int life;
              float happiness;
              signed int hours;
              float sueldo;
              Resource *resource_gathered;
              Resource *resource_exported;
};

#endif
