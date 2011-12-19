#include "TextureManager.h"

TextureManager::TextureManager()
{
  textures = vector<Texture*> (100);        
}

TextureManager::~TextureManager()
{
  textures.clear();                                
}

Texture* TextureManager::getTexture(int id)
{
  return textures[id];
}

void TextureManager::loadTextures(char *filename)
{
  TiXmlNode* xTextures;   
  int texture_id;

  cout << "Loading " << filename << "..." << endl;      
  TiXmlDocument doc(filename);
  bool loadOkay = doc.LoadFile();
  xTextures = doc.FirstChild("textures");
  
  for(TiXmlElement* texture = xTextures->FirstChildElement("texture"); texture != 0; texture = texture->NextSiblingElement("texture"))
  {
      cout << "\tLoading texture " << texture->Attribute("src") << "..." << endl;                            
      sscanf(texture->Attribute("id"), "%d", &texture_id);
      textures[texture_id] = new Texture((char *) texture->Attribute("src"));              
  }
}
