#include "../includes/push_swap.h"

int	find_smallest_number(t_stack *a)
{
	int	min;
	int	list_size;
	int	smallest_number_index;
	int	i;

	min = atoi(a->content);
	list_size = ft_lstsize_rev(a);
	smallest_number_index = list_size;
	i = 1;
	while (i < list_size)
	{
		a = a->prev;
		if (min > atoi(a->content))
		{
			min = atoi(a->content);
			smallest_number_index = i;
		}
		i++;
	}
	return (smallest_number_index);
}

void	sort_case_five(t_stack *a, t_stack *b)
{
	int	list_size;
	int	smallest_number_index;
	(void)b;

	list_size = ft_lstsize_rev(a) - 1;
	smallest_number_index = find_smallest_number(a);
	printf("\x1b[36m[ls = %d]\n\033[m", list_size);
	printf("\x1b[36m[sni = %d]\n\033[m", smallest_number_index);
	if (list_size == smallest_number_index - 1)
		;
	else if (list_size == smallest_number_index)
		cmd_rra(a);
	else
	{
		while ((list_size - 1) > 0)
		{
			cmd_ra(a);
			list_size--;
		}
	}
}