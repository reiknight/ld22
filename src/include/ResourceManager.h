#ifndef CLASS_RESOURCE_MANAGER_H
#define CLASS_RESOURCE_MANAGER_H

#include "Globals.h"
#include "Resource.h"

class ResourceManager
{
  public:
    ResourceManager();
    ~ResourceManager();
    Resource* getResource(int id);
    void loadResources(char *filename);
  private:
    vector<Resource*> resources;     
};

#endif
