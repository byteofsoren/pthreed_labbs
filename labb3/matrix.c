#include "matrix.h"
#include "myRand.h"
#include <stdio.h>
#include <stdlib.h>

Matrix mx_zerros(size_t m, size_t n){
  // Creates a matrix with 0 m rows n cols.
  Matrix mx = NULL;
  size_t tot_size = m*n;
  mx = (Matrix) malloc(sizeof(Matrix));
  mx->m = m;
  mx->n = n;
  mx->data = (Data) malloc(sizeof(Data) * tot_size );
  for (size_t i = 0; i < tot_size; i++) {
    mx->data[i] = 0;
  }
  return mx;
}
Matrix mx_Idetity(size_t m){
  Matrix mx = NULL;
  mx = mx_zerros(m, m);
  for (size_t i = 0; i < m; i++) {
    mx_sett(mx, 1, i, i);
  }
  return mx;
}

Matrix mx_Rand(size_t m, size_t n, int min, int max){
  Matrix mx = NULL;
  mx = mx_zerros(m,n);
  for (size_t row = 0; row < m; row++) {
    for (size_t col = 0; col < n; col++) {
      mx_sett(mx, myRand(min, max), row, col);
    }
  }
  return mx;
}

void mx_sett(Matrix mx, int data, size_t m, size_t n){
  // Sett a specific cell in the matrix to the choisen data.
  if (mx->m >= m && mx->n >= n) {
    //printf("Setting data\n" );
    size_t cols = mx->n;
    size_t index = cols * m + n;
    mx->data[index] = data;
  }
  else {
    printf("--Error out side index--" );
    printf("-- m\tn--\n");
    printf("-in- %ld\t%ld\n", m,n );
    printf("-mx- %ld\t%ld\n", mx->m, mx->n );
    printf("-------------\n");
  }
}
void mx_show(Matrix mx){
  // Shows the matrix on the stdout.
  size_t tot = mx->m * mx->n;
  size_t row_count = 0;
  printf("| " );
  for (size_t i = 0; i < tot; i++) {
    printf("%d ", mx->data[i] );
    row_count++;
    if (row_count == mx->n){
      row_count = 0;
      printf("|\n| " );
    }
  }

}
