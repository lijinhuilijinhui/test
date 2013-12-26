#ifndef _COMMON_H
#define _COMMON_H

#include <string>
#include <stdio.h>

class Object
{
public:
  Object() {
    //printf("Object construct:%p\n", this);
    member = "xxx";
  }
  ~Object() {
    //printf("Object destruct:%p\n", this);
  }
public:
  std::string member;
};

class Wrapper
{
public:
  static int number;
  static const Object obj;
};


#endif
