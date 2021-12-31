#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define max 5

typedef struct stack
{
	struct stack *prev;
	long number;
	int top;
	struct stack? *next;
}	stack;

#include "stdio.h"
#include "stdlib.h"

#endif