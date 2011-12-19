#include "Resource.h"

Resource::Resource(int _id, char *_name, int _category, int time, int _money)
{
  id = _id;
  name = _name;                      
  category = _category;
  hours = time;
  money = _money;
}

int Resource::getMoney() {
  return money;
}

int Resource::getTime() {
  return hours;
}

bool Resource::isPrime()
{
  return category == 0;
}
