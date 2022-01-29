#include "../includes/push_swap.h"

void	sort_case_two(t_stack *a, t_list_info *list_info)
{
	if (strcmp(a->content, (a->prev)->content) > 0)
		cmd_sa(a, list_info);
}
