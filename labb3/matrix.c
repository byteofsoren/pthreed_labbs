#include "matrix.h"
#include "myRand.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

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

Matrix mx_countUp(size_t m, size_t n){
  Matrix mx = mx_zerros(m, n);
  for (size_t i = 0; i < m*n; i++) {
    mx->data[i] = i + 1;
  }
  //mx->data[1]=9;
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
    printf("mx_sett(Matrix mx, int data, size_t m, size_t n)\n" );
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
  printf("\n" );
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

Matrix _subMx(Matrix mx, size_t col){
  // To evalueate determinants you need to create sub matrixes.
  // This function returns a submatrix of given matrix.
  // Inuput:
  //      Matrix mx  is a retangular matrix of n elements
  //      size_t col is the column of the matrix you do not want to include.
  // Return:
  //      Matrix: The returning rectangular matrix is n-1 in size.
  // Also it ignores the top row.
  if (col < mx->n) {
    // Its inside the scope of the matrix.
    Matrix subMx = mx_zerros(mx->m - 1, mx->n -1);
    size_t row_count = 0;
    size_t col_count = 0;
    for (size_t mx_m = 0; mx_m < mx->m; mx_m++) {
      for (size_t mx_n = 0; mx_n < mx->n; mx_n++) {
        if (col != mx_m) {
          mx_sett(subMx, mx_getCell(mx, mx_m, mx_n) , row_count, col_count);
          col_count++;
        }
      }
      row_count++;
    }

    return subMx;
  }else {
    printf("ERROR: Outside domain of input matrix\n" );
  }
  return NULL;
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
        sum = mx->data[0]*mx->data[3] - mx->data[1]*mx->data[2];
        break;
      default:
        // This leads to cofactor evaluation.
        //printf("test\n" );
        // iterate over top row.
        for (size_t top_row_cout = 0; top_row_cout < mx->n; top_row_cout++) {
          // create a sub matrix for eveary top row cell.
          Matrix mxNew = mx_zerros(mx->m - 1, mx->m -1);
          size_t mxNewColumn = 0;
          size_t mxNewRow = 0;
          // fill new matrix with sub matrix excluding the colum pointed ou by top_row_cout
          for (size_t rows = 1; rows < mx->m; rows++) {  // iterate th mx matrix row wise start att row 1 because we do cofactor evaluation over top row.
            for (size_t cols = 0; cols < mx->n; cols++) { // mx matrix columns.
              if (cols != top_row_cout) {
                mx_sett(mxNew, mx_getCell(mx, rows, cols), mxNewRow, mxNewColumn);
                //printf("added to cell mxNewColumn=%ld mxNewRow=%ld\n",mxNewColumn, mxNewRow );
                mxNewColumn++;
              }

            }
            mxNewColumn = 0;
            mxNewRow++;
          }
          //mx_show(mxNew);
          int top_nr = pow(-1,top_row_cout)*mx->data[top_row_cout];
          int sub_sum = mx_det(mxNew);
          //printf("top_nr= %d, sub_sum=%d\n",top_nr, sub_sum );
          sum += top_nr*sub_sum;
          mx_free(mxNew);
        }

    }

  }
  else {
    printf("Not a square matrix\n" );
  }
  //printf("sum = %d\n", sum);
  return sum;
}



void mx_free(Matrix mx){
  mx->data = NULL;
  mx->m = 0;
  mx->n = 0;
  free(mx);
}
