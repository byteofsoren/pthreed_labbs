#include <stdio.h>

#ifndef MATRIX_H
#define MATRIX_H


typedef int *Data;

struct matrix
{
  Data data;
  size_t m;
  size_t n;
};
typedef struct matrix *Matrix;


Matrix mx_zerros(size_t m, size_t n);
Matrix mx_Idetity(size_t m);
Matrix mx_Rand(size_t m, size_t n, int min, int max);
Matrix mx_countUp(size_t m, size_t n);
void mx_sett(Matrix mx, int data, size_t m, size_t n);
void mx_show(Matrix mx);
int mx_getCell(Matrix mx, size_t m, size_t n);
Matrix mx_SubMx(Matrix mx, size_t mStart, size_t mStop, size_t nStart, size_t nStop);
int mx_det(Matrix mx);
void mx_free(Matrix mx);
#endif
