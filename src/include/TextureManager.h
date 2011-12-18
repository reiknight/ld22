#ifndef CLASS_TEXTURE_MANAGER_H
#define CLASS_TEXTURE_MANAGER_H

#include "Globals.h"
#include "Texture.h"

class TextureManager
{
  public:
    TextureManager();
    ~TextureManager();
    void setTexture(int id, char *filename);
    Texture* getTexture(int id);
  private:
    vector<Texture*> textures;     
};

#endif
