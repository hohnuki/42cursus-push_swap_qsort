#include "push_swap.h"

t_stack	*sort_case_three(t_stack *a)
{
	t_stack	*top_stack;
	t_stack	*middle_stack;
	t_stack	*bottom_stack;

	top_stack = a;
	middle_stack = a->prev;
	bottom_stack = (a->prev)->prev;
	if (strcmp(top_stack->content, middle_stack->content) > 0 && strcmp(middle_stack->content, bottom_stack->content) < 0)
		command_sa(a);
	return (a);
}