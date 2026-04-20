#include <stdio.h>
#include <stdlib.h>

#include "inp.h"
#include "matr.h"

Err freeMatrix(Matrix *matrix)
{
	if (matrix == NULL || matrix->matr == NULL)
	{
		return ERR_MEM;
	}

	for (int i = 0; i < matrix->cnt_lines; i++)
	{
		freeLine(matrix->matr + i);	
	}
	free(matrix->matr);
	return ERR_OK;
}

int inputMatrix(Matrix *matrix)
{
	Err code = ERR_OK;
	int inp = 2;
	while (inp == 2)
	{
		printf("введите количество строк: \n");
		inp = input(&matrix->cnt_lines);
		if (inp == EOF)
		{
			return EOF;
		}
	}
	inp = 2;

	matrix->matr = (Line *)calloc(matrix->cnt_lines, sizeof(Line));
	if (matrix->matr == NULL)
	{
		printf("ошибка выделения памяти\n");
		return 1;
	}

	for (int i = 0; i < matrix->cnt_lines; i++)
	{
		while (inp == 2)
		{
			printf("Введите кол-во элементов в строке %d: \n", i + 1);
			inp = input(&matrix->matr[i].cnt_elements);
			if (inp == EOF)
			{
				freeMatrix(matrix);
				return EOF;
			}
		}
		inp = 2;

		code = createLine(matrix->matr + i, matrix->matr[i].cnt_elements);
		printError(code);

		inp = inputLine(matrix->matr + i);
		if (inp == EOF)
		{
			freeMatrix(matrix);
			return EOF;
		}
		inp = 2;
	}
}

Err printMatrix(const Matrix *matrix)
{
	if (matrix == NULL || matrix->matr == NULL)
	{
		return ERR_MATRIX;
	}
	
	printf("Матрица: \n");
	for (int i = 0; i < matrix->cnt_lines; i++)
	{
		printLine(matrix->matr + i);
	}
	return ERR_OK;
}

void initVector(Matrix *matrix, Line *vector)
{
	for (int i = 0; i < matrix->cnt_lines; i++)
	{
		if (matrix->matr[i].cnt_elements == 0)
		{
			vector->arr[i] = 0;
			continue;
		}
		vector->arr[i] = countMaximumEl(matrix->matr + i);
	}
}
