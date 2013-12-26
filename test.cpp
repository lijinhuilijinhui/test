#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <assert.h>
#include "common.h"

using namespace std;

int main()
{
  printf("-----start main\n");
  Wrapper::number++;

  printf("-----begin dlopen liba.so\n");
  void *dp = dlopen("./liba.so", RTLD_LAZY);
  assert(dp);
  void (*funcp)();
  *(void **)(&funcp) = dlsym(dp, "fun");
  (*funcp)();

  printf("-----end main\n");
  return 0;
}

/*
void openlib_and_exec(const char *libname) {
  void *dp = dlopen(libname, RTLD_LAZY);
  char *pszErr = dlerror();
  if( !dp || pszErr )
  {
    printf("** dp Load liba.so failed! error:%s\n", pszErr);
    return;
  }
  void (*funcp)();
  *(void **)(&funcp) = dlsym(dp, "fun");
  (*funcp)();
}
*/
