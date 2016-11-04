#include "matrix.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  //Matrix mx = mx_zerros(3, 3);
  //Matrix mx = mx_Idetity(4);
  Matrix mx = mx_Rand(4,4,2,9);
  //int dt = 1;
  //mx_sett(mx, dt, 2, 1);
  mx_show(mx);
  printf("end\n");
  return 0;
}
