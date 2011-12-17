#include "Resource.h"

Resource::Resource() {
   distance = 0;
   isPrime = 0;
   hours = 1;
}

Resource::Resource(int _distance) {
   distance = _distance;
   isPrime = 1;
   hours = 1;
}

Resource::~Resource() {}
