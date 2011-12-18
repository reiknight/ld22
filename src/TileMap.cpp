#include "TileMap.h"

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
        cout << "\t";
        tiles.push_back(new Tile(xTile->Attribute("name"), xTile->FirstChildElement("sprite")->Attribute("src")));
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
  int x = -((cols/2)*tile_width); 
  int y = ((rows/2)-1)*tile_height;
  
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      tiles[tileset[i][j]]->render(x,y);
      x += tile_width;
    }
    x = -((cols/2)*tile_width);
    y -= tile_height;
  }
}

void TileMap::update(float dt)
{
  for(int i = 0; i < tiles.size(); i++)
  {
    tiles[i]->update(dt);
  }  
}
