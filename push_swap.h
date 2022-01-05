#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				number;
	struct s_stack	*next;
}	t_stack;

#endif