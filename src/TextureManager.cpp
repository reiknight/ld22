#include "TextureManager.h"

TextureManager::TextureManager()
{
  textures = vector<Texture*> (100);             
}

TextureManager::~TextureManager()
{
  textures.clear();                                
}

void TextureManager::setTexture(int id, char *filename)
{
  textures[id] = new Texture(filename);   
}

Texture* TextureManager::getTexture(int id)
{
  return textures[id];
}
