#include "TileMap.h"
#include "Game.h"

TileMap::TileMap(char *filename)
{
  map_file = filename;
  tileset = 0;
  reload();
}

TileMap::~TileMap()
{
  clean();
}

void TileMap::reload()
{
  TiXmlNode* xMap;
  int resource_id;
  
  // Release resources
  clean();
    
  try {
    cout << "Loading " << map_file << "..." << endl;      
    TiXmlDocument doc(map_file);
    bool loadOkay = doc.LoadFile();
    xMap = doc.FirstChildElement("map");
    
    if(xMap != 0)
    {    
      sscanf(xMap->FirstChildElement("tiles")->Attribute("width"), "%d", &tile_width);
      sscanf(xMap->FirstChildElement("tiles")->Attribute("height"), "%d", &tile_height);
      
      for(TiXmlElement* xTile = xMap->FirstChildElement("tiles")->FirstChildElement("tile"); xTile != 0; xTile = xTile->NextSiblingElement("tile"))
      {
        resource_id = -1;
        
        cout << "\t";
        if(xTile->FirstChildElement("resource") != 0)
          sscanf(xTile->FirstChildElement("resource")->Attribute("id"), "%d", &resource_id);
          
        tiles.push_back(new Tile(xTile->FirstChildElement("sprite")->Attribute("src"), resource_id));
      }
      char *xTileset = (char *)xMap->FirstChildElement("tileset")->GetText();
      sscanf((char *)xMap->FirstChildElement("tileset")->Attribute("rows"), "%d", &rows);
      sscanf((char *)xMap->FirstChildElement("tileset")->Attribute("cols"), "%d", &cols);      
      
      tileset = new int*[rows];
      int *line = new int[cols];
      
      int i = 0;
      int j = 0;
      
      while(*xTileset != 0)
      {
        if(*xTileset == ',')
        {
          j++;
        }
        else 
        {
          if(*xTileset == ' ')
          {
            tileset[i] = line;
            i++;
            line = new int[cols]; 
            j = 0;
          }
          else
          {
            sscanf(xTileset,"%d",&line[j]);
          }
        }   
          
        xTileset++;
      }
      tileset[i] = line;
    }
  }catch(exception& e) {
    cout << "Error loading " << map_file << endl;
    cout << e.what() << endl;
  }
             
}

void TileMap::clean()
{
  tiles.clear();
  
  if(tileset != 0)
  {
    for(int i = 0; i < rows; i++)
    {
      delete[] tileset[i];
    }
    delete[] tileset;
  }
}

void TileMap::render()
{
   int pos_x = 0;
   int pos_y = 0;

   for(int i=0; i<rows; i++)
   {
      for(int j=0; j<cols; j++)
      {
         tiles[tileset[i][j]]->render(pos_x,pos_y);
         pos_x += tile_width;
      }
      pos_x = 0;
      pos_y -= tile_height;
   }
}

void TileMap::update(float dt)
{
  for(int i = 0; i < tiles.size(); i++)
  {
    tiles[i]->update(dt);
  }
}

Tile* TileMap::checkClick()
{
  InputManager *im = Game::getInstance()->getInputManager();
  MouseEvent lastClick = im->getLastClick(GLUT_LEFT_BUTTON);

  if(lastClick.isPressed())
  {
    int i = lastClick.getPosition().y / tile_height;
    int j = lastClick.getPosition().x / tile_width;
    tiles[tileset[i][j]]->setPosition(lastClick.getPosition().x, -lastClick.getPosition().y);
    return tiles[tileset[i][j]];
  }
    
  return 0;
}
