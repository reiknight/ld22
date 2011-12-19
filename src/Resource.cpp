#include "Resource.h"

Resource::Resource(int _id, char *_name, int _category, int time)
{
  id = _id;
  name = _name;                      
  category = _category;
  hours = time;
}

bool Resource::isPrime()
{
  return category == 0;
}
