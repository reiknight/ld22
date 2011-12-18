#include "Resource.h"

Resource::Resource(const char *sprite_file) {
   distance = 0;
   isPrime = 0;
   hours = 1;
   sprite = new Sprite((char *)sprite_file);
}

Resource::Resource(int _distance, const char *sprite_file) {
   distance = _distance;
   isPrime = 1;
   hours = 1;
   sprite = new Sprite((char *)sprite_file);
}

Resource::~Resource() {
   delete sprite;
}

void Resource::render(int x, int y)
{
  sprite->render(x,y);
}

void Resource::update(float dt)
{
  sprite->update(dt);
}
