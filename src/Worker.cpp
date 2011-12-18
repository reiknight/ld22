#include "Worker.h"

Worker::Worker(const char *sprite_file) {
     life = 100; //100 as maximun life
     happiness = 0; //Number of life wich will change in the next turn
     task = 0; //Task 0 => No task
     hours = 0; //Hours 0 => No time to the current task
     sueldo = 0.2; //0.2 => 20% of the money go to the Worker
     sprite = new Sprite((char *)sprite_file);
}
Worker::Worker(signed int _life, float _happiness, const char *sprite_file) {
     life = _life;
     happiness = _happiness;
     task = 0; //Task 0 => No task
     hours = 0; //Hours 0 => No time to the current task
     sueldo = 0.2; //0.2 => 20% of the money go to the Worker
     sprite = new Sprite((char *)sprite_file);
}

Worker::~Worker() {
     delete sprite;
}

void Worker::changeLife(int inc) {
     life += inc;
}

void Worker::changeTask(int _task) {
     task = _task;
}

void Worker::changeHours(int h) {
     hours = h;
}

void Worker::render(int x, int y)
{
  sprite->render(x,y);
}

void Worker::update(float dt)
{
  sprite->update(dt);
}
