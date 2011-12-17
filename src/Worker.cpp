#include "Worker.h"

Worker::Worker() {
     life = 100; //100 as maximun life
     happiness = 0; //Number of life wich will change in the next turn
     task = 0; //Task 0 => No task
     hours = 0; //Hours 0 => No time to the current task
     sueldo = 0.2; //0.2 => 20% of the money go to the Worker
}
Worker::Worker(signed int _life, float _happiness) {
     life = _life;
     happiness = _happiness;
     task = 0; //Task 0 => No task
     hours = 0; //Hours 0 => No time to the current task
     sueldo = 0.2; //0.2 => 20% of the money go to the Worker
}

Worker::~Worker() {
     
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
