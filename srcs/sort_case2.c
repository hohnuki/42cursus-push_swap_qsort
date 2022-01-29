#include "../includes/push_swap.h"

void	sort_case_two_a(t_stack *a, t_list_info *list_info)
{
	if (strcmp(a->content, (a->prev)->content) > 0)
		cmd_sa(a, list_info);
}

void	sort_case_two_b(t_stack *b, t_list_info *list_info)
{
	if (strcmp(b->content, (b->prev)->content) > 0)
		cmd_sb(b, list_info);
}
