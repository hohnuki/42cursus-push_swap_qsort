#include "push_swap.h"

t_stack	*insert_sort(t_stack *a)
{
	size_t	i;

	i = 0;
	if (strcmp(a->content, (a->prev)->content) > 0 && strcmp(a->content, ((a->prev)->prev)->content) > 0 && strcmp(a->content, (((a->prev)->prev)->prev)->content) > 0)
		a = cmd_ra(a);
	else
	{
		while (i < 3)
		{
			if (strcmp(a->content, (a->prev)->content) > 0)
				cmd_sa(a);
			a = a->prev;
			i++;
		}
		while (i > 0)
		{
			a = a->next;
			i--;
		}
	}
	return (a);
}

t_stack	*insert_sort_hoge(t_stack *a)
{
	size_t	i;

	i = 0;
	if (strcmp(a->content, (a->prev)->content) > 0 && strcmp(a->content, ((a->prev)->prev)->content) > 0 && strcmp(a->content, (((a->prev)->prev)->prev)->content) > 0)
		a = cmd_ra(a);
	else
	{
		while (i < 4)
		{
			if (strcmp(a->content, (a->prev)->content) > 0)
				cmd_sa(a);
			a = a->prev;
			i++;
		}
		while (i > 0)
		{
			a = a->next;
			i--;
		}
	}
	return (a);
}

t_stack	*sort_case_five(t_stack *a, t_stack *b)
{
	a = cmd_pb(a, b);
	b = b->next;
	a = cmd_pb(a, b);
	b = b->next;
	a = sort_case_three(a);
	b = cmd_pa(a, b);
	a = a->next;
	a = insert_sort(a);
	b = cmd_pa(a, b);
	a = a->next;
	a = insert_sort_hoge(a);
	return (a);
}