#include "Sprite.h"

Sprite::Sprite(int x, int y, char *filename, int frames, float animation_time, int *animation)
{
  this->x = x;
  this->y = y;
  texture = new Texture();
  texture->load(filename,GL_RGBA);
  this->frames = frames;
  current_frame = 0;
  this->animation_time = animation_time;
  counter = 0;
  frame_width = (float) (texture->getWidth() / frames);
  offset_x =  frame_width / texture->getWidth();
  this->animation = animation;
}

Sprite::~Sprite()
{
  delete texture;
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
