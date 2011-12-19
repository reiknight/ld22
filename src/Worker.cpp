#include "Worker.h"

Worker::Worker() : Sprite("assets/worker.xml")
{
  life = 100; //100 as maximun life
  happiness = 0; //Number of life wich will change in the next turn
  hours = 0; //Hours 0 => No time to the current task
  sueldo = 0.2; //0.2 => 20% of the money go to the Worker
  resource = 0;
}

Worker::~Worker() {
 
}

int Worker::getLife() {
  return life;
}

void Worker::changeLife(int inc) {
  life += inc;
}

int Worker::getTime() {
  return hours;    
}
void Worker::changeHours(int h) {
  hours = h;
}
void Worker::changeResource(Resource *res) {
    resource = res;
}
