#include "Game.h"

Game::Game()
{
          
}

Game::~Game()
{
  clean();
}

void Game::reload()
{
  clean();
  
  tm = new TextureManager();
  loadTextures();
  
  scene = new Scene();
}

void Game::clean()
{
  delete tm;
  delete scene;
}

void Game::loop()
{
  float dt;
  
  dt = timer.tick();
  update(dt);
  render();
}

void Game::render()
{
  int x,y;
  char* fps = new char[30];
  
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glColor4f(1.0f,1.0f,1.0f,1.0f);

  scene->render();
  
	glColor3f(1.0f,1.0f,1.0f);
	renderBitmapString(450,450,GLUT_BITMAP_HELVETICA_12,timer.getFPS());

  glutSwapBuffers();
}

void Game::update(float dt)
{
  scene->update(dt);
}

void Game::readKeyboard(char key, bool pressed)
{
  if(key == GLUT_KEY_F1)
  {
    cout << "Reloading game..." << endl;
    reload();
  } else {
    if(key == 27) 
      exit(0);  
  }
}

TextureManager* Game::getTextureManager()
{
  return tm;
}

void Game::loadTextures()
{
  TiXmlNode* xTextures;   
  char *textures_file = "assets/textures.xml";
  int texture_id;
  
  if(tm != 0)
  {
    cout << "Loading " << textures_file << "..." << endl;      
    TiXmlDocument doc(textures_file);
    bool loadOkay = doc.LoadFile();
    xTextures = doc.FirstChild("textures");
    
    for(TiXmlElement* texture = xTextures->FirstChildElement("texture"); texture != 0; texture = texture->NextSiblingElement("texture"))
    {
        cout << "\tLoading texture " << texture->Attribute("src") << "..." << endl;                            
        sscanf(texture->Attribute("id"), "%d", &texture_id);
        tm->setTexture(texture_id, (char *) texture->Attribute("src"));              
    }
  }
}
