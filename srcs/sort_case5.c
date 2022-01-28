#include "../includes/push_swap.h"

t_stack	*insert_sort(t_stack *a)
{
	size_t	i;
	size_t	list_size;

	i = 0;
	list_size = ft_lstsize_rev(a);
	if (atoi(a->content) > atoi(((a->next)->next)->content))
		a = cmd_ra(a);
	else
	{
		while (i < list_size - 1)
		{
			if (atoi(a->content) > atoi((a->prev)->content))
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
	a = insert_sort(a);
	return (a);
}