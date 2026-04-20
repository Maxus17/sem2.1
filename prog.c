#include <stdio.h>
#include <stdlib.h>

#include "line.h"
#include "matr.h"

int main()
{
	Err code = ERR_OK;
	int inp = 0;
	Matrix matrix;
	Line vector;
	while (1)
	{
		inp = inputMatrix(&matrix);
		if (inp == EOF)
		{
			printf("EOF - вы нажали ctrl + D\n");
			return 1;
		}
		printf("Вывод матрицы: \n");
		code = printMatrix(&matrix);
		printError(code);

		code = createLine(&vector, matrix.cnt_lines);
		printError(code);
		initVector(&matrix, &vector);
		printf("Вектор: \n");
		code = printLine(&vector);
		printError(code);
		
		code = freeLine(&vector);
		printError(code);
		
		code = freeMatrix(&matrix);
		printError(code);
	}
	return 0;
}
