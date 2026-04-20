#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "inp.h"
#include "line.h"

Err freeLine(Line *line)
{
	if (line->arr == NULL || line->cnt_elements == 0)
	{
		return ERR_LINE;
	}
	else
	{
		free(line->arr);
	}
	return ERR_OK;
}

Err createLine(Line *line, const int len)
{
	line->arr = (int *)malloc(len * sizeof(int));
	if (line->arr == NULL)
	{
		return ERR_MEM;
	}
	line->cnt_elements = len;
	return ERR_OK;
}

int cmp(const void *a, const void *b)
{
	const int *x = (const int *)a;
	const int *y = (const int *)b;
	return *x - *y;
}

int countMaximumEl(const Line *line)
{
	if (line->arr == NULL || line->cnt_elements == 0)
	{
		return 0;
	}

	qsort(line->arr, line->cnt_elements, sizeof(int), cmp);

	int max_cnt = 1;
	int cnt = 1;

	for (int i = 0; i < line->cnt_elements - 1; i++)
	{
		if (line->arr[i] == line->arr[i + 1])
		{
			cnt++;
			if (cnt > max_cnt)
			{
				max_cnt = cnt;
			}	
		}
		else
		{
			cnt = 1;
		}
	}
	
	return max_cnt;
}

int inputLine(Line *line)
{	
	int inp = 2;
	
	for (int j = 0; j < line->cnt_elements; j++)
	{
		while (inp == 2)
		{
			printf("Введите %d элемент строки: \n", j + 1);
			inp = inputElements(line->arr + j);
			if (inp == EOF)
			{
				return EOF;
			}
		}
		inp = 2;	
	}
	return 0;
}

Err printLine(const Line *vector)
{
	if (vector == NULL || vector->arr == NULL)
	{
		return ERR_LINE;
	}	
	
	for (int i = 0; i < vector->cnt_elements; i++)
	{
		printf("%d ", vector->arr[i]);
	}
	printf("\n");
	return ERR_OK;
}
