#ifndef CLASS_RESOURCE_H
#define CLASS_RESOURCE_H

#include "Globals.h"
#include "Sprite.h"

class Resource {
      public:
             Resource(const char *sprite_file);
             Resource(int _distance, const char *sprite_file);
             ~Resource();
             void render(int x, int y);
             void update(float dt);
      private:
              int distance; //Distance in hours
              int isPrime; //Is a material of type 0?
              int hours; //Hours to get 1 unity from resource
              int resource; //Number of the resource
              Sprite *sprite;
};

#endif
