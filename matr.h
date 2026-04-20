#ifndef MATR_H
#define MATR_H

#include "err.h"
#include "line.h"

typedef struct Matrix{
	int cnt_lines;
	Line *matr;
}Matrix;

Err freeMatrix(Matrix *matrix);
int inputMatrix(Matrix *matrix);
Err printMatrix(const Matrix *matrix);
void initVector(Matrix *matrix, Line *vector);

#endif
