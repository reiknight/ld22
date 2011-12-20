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
     
     int distance = 0;
     workers[i].changeHours(2*distance+value*resource->getTime());
     workers[i].changeResource(resource);
     
     int life = workers[i].getLife();
     money += value*resource->getMoney();
     if(life >  0) {
       int happiness = 8-workers[i].getTime();
       workers[i].changeLife(life + 5*happiness);
     } else {
       end_game = true;
     }
  }

  return end_game;
}

Worker* Player::getWorker(int i)
{
  return &workers[i];
}
