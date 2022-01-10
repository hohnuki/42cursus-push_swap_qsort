#include "push_swap.h"

t_stack	*sort_case_three(t_stack *a)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	top = a;
	middle = a->prev;
	bottom = (a->prev)->prev;
	if (strcmp(top->content, middle->content) > 0 && strcmp(middle->content, bottom->content) < 0 && strcmp(top->content, bottom->content) < 0)
		cmd_sa(a);
	else if (strcmp(top->content, middle->content) > 0 && strcmp(middle->content, bottom->content) > 0)
	{
		cmd_sa(a);
		a = cmd_rra(a);
	}
	else if (strcmp(top->content, middle->content) > 0 && strcmp(middle->content, bottom->content) < 0 && strcmp(top->content, bottom->content) > 0)
		a = cmd_ra(a);
	else if (strcmp(top->content, middle->content) < 0 && strcmp(middle->content, bottom->content) > 0 && strcmp(top->content, bottom->content) < 0)
	{
		cmd_sa(a);
		a = cmd_ra(a);
	}
	else if (strcmp(top->content, middle->content) < 0 && strcmp(middle->content, bottom->content) > 0 && strcmp(top->content, bottom->content) > 0)
		a = cmd_rra(a);
	return (a);
}
