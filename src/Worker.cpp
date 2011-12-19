#include "Worker.h"

Worker::Worker() : Sprite("assets/worker.xml")
{
  life = 100; //100 as maximun life
  happiness = 0; //Number of life wich will change in the next turn
  hours = 0; //Hours 0 => No time to the current task
  sueldo = 0.2; //0.2 => 20% of the money go to the Worker
  resource_gathered = 0;
  resource_exported = 0;
}

Worker::~Worker() {
 
}

void Worker::changeLife(int inc) {
  life += inc;
}

void Worker::changeHours(int h) {
  hours = h;
}
void Worker::changeResource(bool isGathered, Resource *res) {
  if(isGathered) {
    resource_gathered = res;
    resource_exported = NULL;
  } else {
    resource_gathered = NULL;
    resource_exported = res;
  }
}
