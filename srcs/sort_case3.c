#include "../includes/push_swap.h"

void	sort_case_three(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = atoi(a->content);
	middle = atoi((a->prev)->content);
	bottom = atoi(((a->prev)->prev)->content);
	if (top > middle && bottom > middle && bottom > top)
		cmd_sa(a);
	else if (top > middle && middle > bottom)
	{
		cmd_sa(a);
		cmd_rra(a);
	}
	else if (top > middle && bottom > middle && top > bottom)
		cmd_ra(a);
	else if (middle > top && middle > bottom && bottom > top)
	{
		cmd_sa(a);
		cmd_ra(a);
	}
	else if (middle > top && middle > bottom && top > bottom)
		cmd_rra(a);
}
