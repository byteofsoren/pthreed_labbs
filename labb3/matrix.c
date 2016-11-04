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

size_t _index(Matrix mx, size_t m, size_t n){
  // Calculates and returns the indexing of the array
  size_t cols = mx->n;
  return cols * m + n;
}

void mx_sett(Matrix mx, int data, size_t m, size_t n){
  // Sett a specific cell in the matrix to the choisen data.
  if (mx->m >= m && mx->n >= n) {

    mx->data[_index(mx,  m,  n)] = data;
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

int mx_getCell(Matrix mx, size_t m, size_t n){
  // returns the data form a cell in the matrix.
  if (m < mx->m && n < mx->n) {
    return mx->data[_index(mx, m, n)];
  }
  else {
    printf("Error outside matrix\n" );
  }
  return 0;
}

Matrix mx_SubMx(Matrix mx, size_t mStart, size_t mStop, size_t nStart, size_t nStop){
  size_t mNew = mStop - mStart;
  size_t nNew = nStop - mStart;
  Matrix mxNew = mx_zerros(mNew,nNew);  // Creates a new matrix to store data in.
  size_t mCounter = 0;
  size_t nCounter = 0;
  for (size_t i = mStart; i < mStop; i++) {
    for (size_t j = nStart; j < nStop; j++) {
      mx_sett(mxNew, mx_getCell(mx, i, j), mCounter, nCounter);
      nCounter++;
    }
    nCounter = 0;
    mCounter++;
  }
  return mxNew;
}

int mx_det(Matrix mx){
  // Calculates the determinant of an matrix.
  int sum = 0;
  if (mx->m == mx->n) {
    // Make shure that the matrix is asquare matrix.
    switch (mx->n) {
      case 1:
        return mx->data[0];
        break;
      case 2:
        return mx->data[0]*mx->data[3] - mx->data[1]*mx->data[2];
        break;
      default:
        // This leads to cofactor evaluation.
        printf("test\n" );
        // iterate over top row.
        for (size_t top_row_cout = 0; top_row_cout < mx->n; top_row_cout++) {
          // create a sub matrix for eveary top row cell.
          Matrix mxNew = mx_zerros(mx->m - 1, mx->m -1);
          // fill new matrix with sub matrix excluding the colum pointed ou by top_row_cout
          size_t newCol = 0;
          size_t newRow = 0;
          for (size_t row = 1; row < mx->m; row++) {
            for (size_t col = 0; col < mx->n; col++) {
              if (top_row_cout != col) {
                mx_sett(mxNew,mx_getCell( mx, row , col ), newRow, newCol );
                newCol++;
              }

            }
            newRow++;
          }
          mx_show(mxNew);
          mx_free(mxNew);
        }

    }

  }
  else {
    printf("Not a square matrix\n" );
  }
  return sum;
}

void mx_free(Matrix mx){
  mx->data = NULL;
  mx->m = 0;
  mx->n = 0;
  free(mx);
}
