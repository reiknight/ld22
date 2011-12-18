#include "Resource.h"

Resource::Resource(int _id, char *_name, int category, int time)
{
  id = _id;
  name = _name;                      
  isPrime = category == 0;
  hours = time;
}
