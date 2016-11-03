#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

struct matrix{
  char **array;
  int size;
};

// This time i whill add wait for thread to close program.
void *threadFun(void *arg) {
  char *str;
  str = (char*) arg;
  for (size_t i = 0; i < 10; i++) {
    sleep(1);
    printf("threadFun sasy %s\n", str );
  }
  return NULL;
}

void *calc(void *start) {
  // Sending a numerical value to string.
  size_t *value;
  value = (size_t*) start;
  printf("value = %ld\n", *value );
  return (void*) value;
}

void *det(void *matrix) {

  return NULL;
}

void calcDet() {
  // Calculate determinant.
  // ElementType* array = malloc(sizeof(ElementType)*size);
  struct matrix* A = malloc(sizeof(matirx));
  A->size = 2;
}

int main(int argc, char const *argv[]) {
  pthread_t trd, trdCalc;
  char *str = "Hello..";
  size_t value = 15;
  size_t *pt_val = &value;
  pthread_create(&trdCalc, NULL, calc, pt_val);
  pthread_create(&trd, NULL,threadFun , str);
  pthread_join(trd, NULL);
  printf("End of prog\n" );

  return 0;
}
