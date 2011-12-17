#include "Sprite.h"

Sprite::Sprite(char *filename)
{
  sprite_file = filename;
  reload();
}

Sprite::~Sprite()
{
  clean();
}

void Sprite::reload()
{
  rapidxml::xml_document<> doc;
  rapidxml::xml_node<> *sprite;
  char *buf;
  
  // Release resources
  clean();
    
  try {
    cout << "Loading " << sprite_file << "..." << endl;      
    buf = readFileContents(sprite_file);
    doc.parse<0>(buf);
    sprite = doc.first_node("sprite");
    
    if(sprite != 0)
    {    
      //position           
      sscanf(sprite->first_node("position")->first_attribute("x")->value(), "%d", &x);
      sscanf(sprite->first_node("position")->first_attribute("y")->value(), "%d", &y);
      //texture
      texture = new Texture();
      texture->load((char *)sprite->first_node("texture")->first_attribute("src")->value(),GL_RGBA);
      sscanf(sprite->first_node("frames")->value(), "%d", &frames);
      //animation
      current_frame = 0;
      counter = 0;
      frame_width = (float) (texture->getWidth() / frames);
      offset_x =  frame_width / texture->getWidth();
      sscanf(sprite->first_node("animation")->first_attribute("time")->value(), "%f", &animation_time);
      
      for(rapidxml::xml_node<> *frame = sprite->first_node("animation")->first_node("frame"); frame != 0; frame = frame->next_sibling("frame"))
      {
        int value;
        sscanf(frame->value(), "%d", &value);
        animation.push_back(value);
      }
    }
  }catch(...) {
    cout << "Error loading " << sprite_file << endl;
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
  counter += dt;
  if(counter > animation_time)
  {
    counter = 0;
    current_frame = (current_frame + 1) % 3; //TODO: hardcoded
  }
}

void Sprite::render()
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(x, y, 0);
  
  // Draw texture
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
  
  // Bounding Box
  glColor3f(0.0f, 0.0f, 0.0f);
  glPolygonMode(GL_FRONT, GL_LINE);
  glBegin(GL_QUADS);
    glVertex2f(frame_width, 0.0f);
    glVertex2f(frame_width, texture->getHeight());
    glVertex2f(0.0f, texture->getHeight());
    glVertex2f(0.0f, 0.0f);
  glEnd();
  glPolygonMode(GL_FRONT, GL_FILL);
  
  glPopMatrix();
}
