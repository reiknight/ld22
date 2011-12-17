#include "Sprite.h"

Sprite::Sprite(char *filename)
{
  texture = 0;
  sprite_file = filename;
  reload();
}

Sprite::~Sprite()
{
  clean();
}

void Sprite::reload()
{
  TiXmlNode* xSprite;
  
  // Release resources
  clean();
    
  try {
    cout << "Loading " << sprite_file << "..." << endl;      
    TiXmlDocument doc(sprite_file);
    bool loadOkay = doc.LoadFile();
    xSprite = doc.FirstChild("sprite");
    
    if(xSprite != 0)
    {    
      //position           
      sscanf(xSprite->FirstChildElement("position")->Attribute("x"), "%d", &x);
      sscanf(xSprite->FirstChildElement("position")->Attribute("y"), "%d", &y);
      //texture
      texture = new Texture();
      texture->load((char *)xSprite->FirstChildElement("texture")->Attribute("src"),GL_RGBA);
      sscanf(xSprite->FirstChildElement("animation")->Attribute("frames"), "%d", &frames);
      //animation
      current_frame = 0;
      counter = 0;
      frame_width = (float) (texture->getWidth() / frames);
      offset_x =  frame_width / texture->getWidth();
      sscanf(xSprite->FirstChildElement("animation")->Attribute("time"), "%f", &animation_time);
      
      for(TiXmlElement* frame = xSprite->FirstChildElement("animation")->FirstChildElement("frame"); frame != 0; frame = frame->NextSiblingElement("frame"))
      {
        int value;
        sscanf(frame->GetText(), "%d", &value);
        animation.push_back(value);
      }
    }
  }catch(exception& e) {
    cout << "Error loading " << sprite_file << endl;
    cout << e.what() << endl;
  }              
}

void Sprite::clean()
{
  if(texture != 0)
    delete texture;
 
  animation.clear();    
}

void Sprite::update(float dt)
{
  if(animation_time > 0)
  {
    counter += dt;
    if(counter > animation_time)
    {
      counter = 0;
      current_frame = (current_frame + 1) % animation.size();
    }
  }
}

void Sprite::render()
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(x, y, 0);
  
  // Draw texture
  if(texture != 0)
  {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture->getId());
    glBegin(GL_QUADS);
      glTexCoord2f((animation[current_frame] + 1) * offset_x, 1.0f);  
      glVertex2f(frame_width, 0.0f);
      glTexCoord2f((animation[current_frame] + 1) * offset_x, 0.0f);
      glVertex2f(frame_width, texture->getHeight());
      glTexCoord2f(animation[current_frame] * offset_x, 0.0f);
      glVertex2f(0.0f, texture->getHeight());
      glTexCoord2f(animation[current_frame] * offset_x, 1.0f);
      glVertex2f(0.0f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
  }
  
  glPopMatrix();
}

void Sprite::render(int _x, int _y)
{
  x = _x;
  y = _y;
  render();
}
