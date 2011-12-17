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
