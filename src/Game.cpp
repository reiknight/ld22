#include "Game.h"

Game::Game()
{
  reload();            
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
  
  //sprite = new Sprite("assets/turtle.xml");
  //map = new TileMap("assets/map.xml");
}

void Game::clean()
{
  delete tm;
  //delete sprite;
  //delete map;
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

  //map->render();
  //sprite->render();
    
  drawAxis();
  
	glColor3f(1.0f,1.0f,1.0f);
	renderBitmapString(450,450,GLUT_BITMAP_HELVETICA_12,timer.getFPS());

  glutSwapBuffers();
}

void Game::update(float dt)
{
  //map->update(dt);
  //sprite->update(dt);
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
        cout << "\t Loading texture " << texture->Attribute("src") << "..." << endl;                            
        sscanf(texture->Attribute("id"), "%d", &texture_id);
        tm->setTexture(texture_id, (char *) texture->Attribute("src"));              
    }
  }
}
