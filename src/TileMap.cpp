#include "TileMap.h"

TileMap::TileMap(char *filename)
{
  map_file = filename;
  reload();
}

TileMap::~TileMap()
{
  clean();
}

void TileMap::reload()
{
  TiXmlNode* xMap;
  
  // Release resources
  clean();
    
  try {
    cout << "Loading " << map_file << "..." << endl;      
    TiXmlDocument doc(map_file);
    bool loadOkay = doc.LoadFile();
    xMap = doc.FirstChild("map");
    
    if(xMap != 0)
    {    
      for(TiXmlElement* xTile = xMap->FirstChildElement("tiles")->FirstChildElement("tile"); xTile != 0; xTile = xTile->NextSiblingElement("tile"))
      {
        tiles.push_back(new Tile(xTile->Attribute("name"), xTile->FirstChildElement("sprite")->Attribute("src")));
      }
    }
  }catch(exception& e) {
    cout << "Error loading " << map_file << endl;
    cout << e.what() << endl;
  }    
             
}

void TileMap::clean()
{

}

void TileMap::render()
{
  tiles[0]->render(100,100);
  tiles[1]->render(200,100);
}

void TileMap::update(float dt)
{
     
}
