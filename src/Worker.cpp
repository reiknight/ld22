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
  
  if(life > 100)
    life = 100;
  
  if(life < 30)
    setCurrentFrame(2);
  else if(life < 70)
    setCurrentFrame(1);
  else
    setCurrentFrame(0);
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
