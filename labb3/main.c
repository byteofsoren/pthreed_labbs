#include "matrix.h"
#include <stdio.h>

void test_det(){
  //size_t n = 4;
  //Matrix mx = mx_Rand(n,n,1,9);
  //Matrix mx = mx_Idetity(n);
  //Matrix mx = mx_countUp(n, n);
  //mx_show(mx);
  //printf("result %d\n", mx_det(mx) );
  //Matrix mxs = _subMx(mx, 0);
  //mx_show(mxs);
  //mx_free(mx);

}

int main(int argc, char const *argv[]) {
  //test_det();
  //Matrix mx = mx_zerros(3, 3);
  //Matrix mx = mx_Idetity(4);
  Matrix mx = mx_Rand(60,60,2,9);
  int det = mx_det(mx);
  mx_show(mx);
  printf("%d\n", det);
  //printf("a the cell [1,1] is %d\n",mx_getCell(mx, 1, 1) );
  //Matrix subMx = mx_SubMx(mx, 0,3,0,3);
  //int dt = 1;
  //mx_sett(mx, dt, 2, 1);
  //printf("Orginal matrix\n" );
  //mx_show(mx);
  //printf("Sub matrix\n" );
  //mx_show(subMx);
  printf("end\n");
  return 0;
}
