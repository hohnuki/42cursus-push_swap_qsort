#include "push_swap.h"

static t_stack	*pass_smallest_value_to_b(t_stack *a, t_stack *b)
{
	int	lst_size;
	int	i;
	int	min;
	int	min_index;

	lst_size = ft_lstsize_rev(a);
	i = 1;
	min_index = 0;
	min = atoi(a->content);
	a = a->prev;
	while (i < lst_size)
	{
		if (min > atoi(a->content))
		{
			min = atoi(a->content);
			min_index = i;
		}
		a = a->prev;
		i++;
	}
	a = a->prev;
	if (min_index == 5)
		a = cmd_rra(a);
	else
	{
		while (min_index > 0)
		{
			a = cmd_ra(a);
			min_index--;
		}
	}
	a = cmd_pb(a, b);
	return (a);
}

t_stack	*sort_case_six(t_stack *a, t_stack *b)//TODO:手数を減らす
{
	a = pass_smallest_value_to_b(a, b);
	b = b->next;
	a = pass_smallest_value_to_b(a, b);
	b = b->next;
	a = pass_smallest_value_to_b(a, b);
	b = b->next;
	if (ft_lstsize_rev(a) == 2)
		a = sort_case_two(a);
	else
		a = sort_case_three(a);
	b = sort_case_three(b);
	b = cmd_rb(b);
	cmd_sb(b);
	b = cmd_pa(a, b);
	a = a->next;
	b = cmd_pa(a, b);
	a = a->next;
	b = cmd_pa(a, b);
	a = a->next;
	return (a);
}