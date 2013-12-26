#include <stdio.h>
#include "common.h"

extern "C" void fun() {
  printf("call fun in lib\n");
  Wrapper::number++;
}

