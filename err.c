#include <stdio.h>

#include "err.h"

void printError(Err code)
{
	switch(code)
	{
		case ERR_OK:
			break;
		case ERR_MEM:
			printf("Ошибка выделения памяти\n");
			break;
		case ERR_LINE:
			printf("пустая строка\n");
			break;
		case ERR_MATRIX:
			printf("пустая матрица\n");
			break;
	}
}
