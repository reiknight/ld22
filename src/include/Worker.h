#ifndef CLASS_WORKER_H
#define CLASS_WORKER_H

#include "Globals.h"
#include "Sprite.h"

class Worker {
      public:
             Worker(const char *sprite_file);
             Worker(signed int life, float happiness, const char *sprite_file);
             ~Worker();
             void render(int x, int y);
             void update(float dt);
             void changeLife(int inc);
             void changeTask(int _task);
             void changeHours(int h);
      private:
              signed int life;
              float happiness;
              signed int task;
              signed int hours;
              float sueldo;
              Sprite *sprite;
};

#endif
