#ifndef VECROT_H
#define VECROT_H

#include "err.h"

typedef struct Line{
	int cnt_elements;
	int *arr;
}Line;

Err freeLine(Line *line);
Err createLine(Line *line, const int len);
int cmp(const void *a, const void *b);
int countMaximumEl(const Line *line);
int inputLine(Line *line);
Err printLine(const Line *vector);

#endif
