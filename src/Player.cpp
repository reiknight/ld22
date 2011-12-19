#include "Player.h"
#include "ResourceManager.h"
#include "Resource.h"
#include "Select.h"
#include "Game.h"

Player::Player(char *sprite_file) : Sprite(sprite_file) {
   money = 0; //No score in the beginning
   happiness = 0; //No happiness
   n_workers = 10;
   workers = new Worker[10];
}

Player::~Player() {
}

void Player::incMoney(int inc) {
   money += inc;
}

void Player::incHappiness(int inc) {
   happiness += inc;
}

bool Player::endTurn(vector<Select *> selects, vector<TextInput *> text_inputs)
{     
  ResourceManager* rm = Game::getInstance()->getResourceManager();
  Resource *resource;
  bool end_game = false;
  
  for(int i = 0; i < 10; i ++) {
     int value = 0;
     resource = rm->getResource(selects[i]->getOptionSelected());
     sscanf(text_inputs[i]->getValue(),"%d", &value);
     workers[i].changeHours(value);
     workers[i].changeResource(resource->isPrime(), resource);   
  }
  
  // por cada worker, miramos su recurso
  // increementar dinero
  // comprobar felicidad
  
  // mirar condicion de derrota
  // si end_game es true se acaba
  return end_game;
}
