#include "../includes/push_swap.h"

t_stack	*sort_case_two(t_stack *a)
{
	if (strcmp(a->content, (a->prev)->content) > 0)
		cmd_sa(a);
	return (a);
}
