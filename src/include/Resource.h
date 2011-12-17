#ifndef CLASS_WORKER_H
#define CLASS_WORKER_H

#include "Globals.h"

class Resource {
      public:
             Resource();
             Resource(int _distance);
             ~Resource();
      private:
              int distance; //Distance in hours
              int isPrime; //Is a material of type 0?
              int hours; //Hours to get 1 unity from resource
              int resource; //Number of the resource
};

#endif
