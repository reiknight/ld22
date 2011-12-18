#include "Sprite.h"
#include "Game.h"

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
  int texture_id;
  
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
      sscanf(xSprite->FirstChildElement("texture")->Attribute("id"), "%d", &texture_id);
      texture = Game::getInstance()->getTextureManager()->getTexture(texture_id);
      //animation      
      current_frame = 0;
      counter = 0;
      sscanf(xSprite->FirstChildElement("animation")->Attribute("frames"), "%d", &frames);
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

float Sprite::distance(Sprite p) {
      int A = x - p.x;
      int B = y - p.y;
      return sqrt(pow(A,2) + pow(B,2)); //SQRT((x-a)� + (x-b)�)
}
