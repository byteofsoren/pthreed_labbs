#include <stdio.h>
#include <pthread.h>
#include "myRand.h"

void* do_loop(void *data) {

  int id = *((int*) data);
  size_t delay = 5000;
  if (id == 1){ delay = 60000;}
  for (size_t i = 0; i < 40; i++) {
    for (size_t n = 0; n < delay; n++) {
      // Delay loop
    }
    if (id == 1) {
      printf("----- Threded function \n");
    }
    else {
      printf("In main\n");
    }
  }
  return data;
}

int main(int argc, char const *argv[]) {
  size_t thrd_id;
  int id_thr = 1;
  int id_main = 2;

  pthread_t p_thread;
  thrd_id = pthread_create(&p_thread,NULL,do_loop, &id_thr);
  printf("Started thrd_id=%ld\n", thrd_id);
  do_loop((void*)&id_main);

  return 0;
}
