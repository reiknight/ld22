#include "Globals.h"
#include "Game.h"

void renderCallback();
void keyDownCallback(unsigned char key, int x, int y);
void keyUpCallback(unsigned char key, int x, int y);
void keySpecialCallback(int key, int x, int y);
void changeSize(int w, int h);
void idleCallback();

void setupRC();

int main(int argc, char **argv)
{
	int res_x,res_y,pos_x,pos_y;
	
	//GLUT Initialization
	glutInit(&argc,argv);
	
	//RGBA with double buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE);
	
	//Create centered window
	res_x = glutGet(GLUT_SCREEN_WIDTH);
	res_y = glutGet(GLUT_SCREEN_HEIGHT);
	pos_x = (res_x>>1)-(GAME_WIDTH>>1);
	pos_y = (res_y>>1)-(GAME_HEIGHT>>1);
	glutInitWindowPosition(pos_x,pos_y);
	glutInitWindowSize(GAME_WIDTH,GAME_HEIGHT);
	glutCreateWindow("Ludum Dare");
	
	//Register callbacks
	glutDisplayFunc(renderCallback);
	glutKeyboardFunc(keyDownCallback);		
	glutKeyboardUpFunc(keyUpCallback);
	glutSpecialFunc(keySpecialCallback);
	glutReshapeFunc(changeSize);
	glutIdleFunc(idleCallback);
	
	//Setup Render Context
	setupRC();
	
	//Run game
	glutMainLoop();   
}

void renderCallback()
{
  Game::getInstance()->render();
}

void keyDownCallback(unsigned char key, int x, int y)
{
  Game::getInstance()->readKeyboard(key, true);
}

void keyUpCallback(unsigned char key, int x, int y)
{
  Game::getInstance()->readKeyboard(key, false);     
}

void keySpecialCallback(int key, int x, int y)
{
  Game::getInstance()->readKeyboard(key, true);
}

void changeSize(int w, int h)
{
  GLfloat aspectRatio;

  if(h == 0) h = 1;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  aspectRatio = (GLfloat)w / (GLfloat)h;
  if(w <= h)
  {
    glOrtho(-SCENE_WIDTH, SCENE_WIDTH, -100 / aspectRatio, SCENE_HEIGHT / aspectRatio, 1.0, -1.0);
  }
  else
  {
    glOrtho(-SCENE_WIDTH * aspectRatio, SCENE_WIDTH * aspectRatio, -SCENE_HEIGHT, SCENE_HEIGHT, 1.0, -1.0);
  }
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();	 
}

void idleCallback()
{
  Game::getInstance()->loop();     
}

void setupRC()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glAlphaFunc(GL_GREATER, 0.05f);
  glEnable(GL_ALPHA_TEST);
}
