#ifndef CLASS_WORKER_H
#define CLASS_WORKER_H

#include "Globals.h"

class Worker {
      public:
             Worker();
             Worker(signed int life, float happiness);
             ~Worker();
             void changeLife(int inc);
             void changeTask(int task);
             void changeHours(int h);
      private:
              signed int life;
              float happiness;
              signed int task;
              signed int hours;
              float sueldo;
};

#endif
