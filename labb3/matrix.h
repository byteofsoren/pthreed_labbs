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
void mx_sett(Matrix mx, int data, size_t m, size_t n);
void mx_show(Matrix mx);
#endif
