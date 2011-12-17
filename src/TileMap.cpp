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
  rapidxml::xml_document<> doc;
  rapidxml::xml_node<> *TileMap;
  char *buf;
  Tile *tile;
  vector<Tile*>::iterator it = tiles.begin();
  int id;
  
  // Release resources
  clean();
    
  try {
    cout << "Loading " << map_file << "..." << endl;      
    buf = readFileContents(map_file);
    doc.parse<0>(buf);
    TileMap = doc.first_node("map");
    
    if(TileMap != 0)
    {    
      for(rapidxml::xml_node<> *tile_node = TileMap->first_node("tiles")->first_node("tile"); tile_node != 0; tile_node = tile_node->next_sibling("tile"))
      {
        //sprintf(tile_node->first_node("id")->value(), "%d", &id);
        //tile = new Tile(tile_node->first_node("name")->value(), tile_node->first_node("sprite")->first_attribute("src")->value());
        //tiles.insert(it+id, tile);
      }
      
      /*//position           
      sscanf(sprite->first_node("position")->first_attribute("x")->value(), "%d", &x);
      sscanf(sprite->first_node("position")->first_attribute("y")->value(), "%d", &y);
      //texture
      texture = new Texture();
      texture->load((char *)sprite->first_node("texture")->first_attribute("src")->value(),GL_RGBA);
      sscanf(sprite->first_node("frames")->value(), "%d", &frames);
      //animation
      current_frame = 0;
      counter = 0;
      frame_width = (float) (texture->getWidth() / frames);
      offset_x =  frame_width / texture->getWidth();
      sscanf(sprite->first_node("animation")->first_attribute("time")->value(), "%f", &animation_time);
      
      for(rapidxml::xml_node<> *frame = sprite->first_node("animation")->first_node("frame"); frame != 0; frame = frame->next_sibling("frame"))
      {
        int value;
        sscanf(frame->value(), "%d", &value);
        animation.push_back(value);
      }*/
    }
  }catch(...) {
    cout << "Error loading " << map_file << endl;
  }                   
}

void TileMap::clean()
{
  tiles.clear();
}

void TileMap::render()
{
     
}

void TileMap::update(float dt)
{
     
}
