#ifndef CLASS_TEXTURE_H
#define CLASS_TEXTURE_H

#include "Globals.h"
#include "corona.h"

class Texture
{
  public:
    Texture(char *filename);
    ~Texture();
    GLuint getId();
    int getWidth();
    int getHeight();
  private:
    bool load(const char *filename,int type = GL_RGBA,int wraps = GL_REPEAT,int wrapt = GL_REPEAT, 
      int magf = GL_NEAREST,int minf = GL_NEAREST,bool mipmap = false);
    GLuint id;
    int width;
    int height;
};

#endif
