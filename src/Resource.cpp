#include "Resource.h"

Resource::Resource() : Sprite("assets/resource.xml") {
   distance = 0;
   isPrime = 0;
   hours = 1;
}

Resource::Resource(int _distance) : Sprite("assets/resource.xml") {
   distance = _distance;
   isPrime = 1;
   hours = 1;
}
