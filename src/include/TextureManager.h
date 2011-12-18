#ifndef CLASS_TEXTURE_MANAGER_H
#define CLASS_TEXTURE_MANAGER_H

#include "Globals.h"
#include "Texture.h"

class TextureManager
{
  public:
    TextureManager();
    ~TextureManager();
    Texture* getTexture(int id);
    void loadTextures(char *filename);
  private:
    vector<Texture*> textures;     
};

#endif
