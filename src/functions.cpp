#include "functions.h"

char* readFileContents(char *filename)
{  
  FILE *fp;
  long len;
  char *buf;
  
  fp=fopen(filename,"rb");
  if(fp == 0)
    throw exception();
  
  fseek(fp,0,SEEK_END); //go to end
  len=ftell(fp); //get position at end (length)
  fseek(fp,0,SEEK_SET); //go to beg.
  buf=(char *)malloc(len); //malloc buffer
  fread(buf,len,1,fp); //read into buffer
  fclose(fp);
 
  return buf;
}

void renderBitmapString(float x, float y, void *font, char *string)
{
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void drawAxis()
{
  glBegin(GL_LINES);
  glColor3f(1.0,0.0f,0.0f);
  glVertex3f(0,0,0);
  glVertex3f(SCENE_WIDTH,0,0);
  glVertex3f(0,0,0);
  glVertex3f(-SCENE_WIDTH,0,0);
  glColor3f(0.0,1.0f,0.0f);
  glVertex3f(0,0,0);
  glVertex3f(0,SCENE_HEIGHT,0);
  glVertex3f(0,0,0);
  glVertex3f(0,-SCENE_HEIGHT,0);
  glEnd();      
}
