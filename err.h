#ifndef ERR_H
#define ERR_H

typedef enum Err
{
	ERR_OK = 0,
	ERR_MEM = -1,
	ERR_LINE = -2,
	ERR_MATRIX = -3,
}Err;

void printError(Err code);

#endif
