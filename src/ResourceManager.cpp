#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
  resources = vector<Resource*> (100);             
}

ResourceManager::~ResourceManager()
{
  resources.clear();                                
}

Resource* ResourceManager::getResource(int id)
{
  return resources[id];
}

void ResourceManager::loadResources(char *filename)
{
  TiXmlNode* xResources;   
  int id;
  int category;
  int time = 0;
  int money;

  cout << "Loading " << filename << "..." << endl;      
  TiXmlDocument doc(filename);
  bool loadOkay = doc.LoadFile();
  xResources = doc.FirstChild("resources");
  
  for(TiXmlElement* resource = xResources->FirstChildElement("resource"); resource != 0; resource = resource->NextSiblingElement("resource"))
  {
      cout << "\tLoading resource " << resource->Attribute("name") << "..." << endl;                            
      sscanf(resource->Attribute("id"), "%d", &id);
      sscanf(resource->Attribute("category"), "%d", &category);
      sscanf(resource->Attribute("time"), "%d", &time);
      sscanf(resource->Attribute("money"),"%d", &money);
      resources[id] = new Resource(id, (char *)resource->Attribute("name"), category, time, money); 
  }
}

