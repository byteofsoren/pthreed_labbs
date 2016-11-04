#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myRand.h"

int myRand(int min, int max){
// This is my random number generator
  int result = 0 , low = 0 ,hig = 0;
  static int oneTime = 0;   // Srand patch

  if ( min < max) {
    low = min;
    hig = max + 1;        // include the max result in the output
  }  else {
    low = max + 1;        // include the max result in the output
    hig = min;
  }
  if (oneTime == 0) {     // you only run srand 1 time.
    srand(time(NULL));
    oneTime++;
  }
  result = rand() % (hig - low)+ low;  /* What this do is better expalined with an exampel.
  Lest say you get;
    rand()=234532   hig=20    low=5
    first evaluet (hig-low)=15
    then 234532 % 15 = 7
    last 7 + 5 = 12  */
  return result;
}
