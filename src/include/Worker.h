#ifndef CLASS_WORKER_H
#define CLASS_WORKER_H

#include "Globals.h"
#include "Sprite.h"
#include "Resource.h"

class Worker : public Sprite {
      public:
             Worker();
             ~Worker();
             void changeLife(int inc);
             void changeHours(int h);
             void changeResource(Resource* res);
             int getTime();
             int getLife();
      private:
              signed int life;
              float happiness;
              signed int hours;
              float sueldo;
              Resource *resource;
};

#endif
