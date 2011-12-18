#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Globals.h"

char* readFileContents(char *filename); 
void renderBitmapString(float x, float y, void *font, char *string);
void drawAxis();

#endif
