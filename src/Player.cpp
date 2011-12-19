#include "Player.h"

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

void Player::endTurn(vector<Select *> selects, vector<TextInput *> text_inputs)
{
  //worker[0] <- es el primer worker
  
  //assign select values to workers
  
  //a efectos practicos, el "option_selected" es
  //la id del resource. Se puede obtener
  //via ResourceManager y asignar a Worker
      
  //de los text_inputs, usando getVAlue() nos devuelve
  //el numero de horas (en char*, se tiene que castear a
  //int usando sscanf
}
