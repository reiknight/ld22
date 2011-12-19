#ifndef CLASS_RESOURCE_H
#define CLASS_RESOURCE_H

#include "Globals.h"

class Resource {
  public:
    Resource(int _id, char *_name, int _category, int time, int _money);
    ~Resource();
    bool isPrime();
    int getMoney();
    int getTime();
  private:
    int id; //Number of the resource
    char *name;
    int category; //Is a material of type 0?
    int hours; //Hours to get 1 unity from resource
    int money;
};

#endif
