#include "../includes/push_swap.h"

int	main(int argc, char **argv)//TODO:重複
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*start_a;
	t_stack	*tmp;
	int	i;

	i = argc - 1;
	a = ft_lstnew(NULL);
	b = ft_lstnew(NULL);
	b->last_node = b;
	start_a = a;
	while (i > 0)
	{
		tmp = ft_lstnew(argv[i]);
		if (ps_atoi(tmp->content) > INT_MAX || ps_atoi(tmp->content) < INT_MIN)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		tmp->prev = a;
		a->next = tmp;
		a = tmp;
		if (i == 1)
		{
			a->next = start_a;
			start_a->prev = a;
			a->last_node = a;
		}
		i--;
	}
	if ((argc - 1) == 0)
		return (0);
	else if ((argc - 1) == 2)
		sort_case_two(a);
	else if ((argc - 1) == 3)
		sort_case_three(a);
//	else if ((argc - 1) == 5)
//		sort_case_five(a, b);
//	else if ((argc - 1) == 6)
//		sort_case_six(a, b);
//	else
//		sort_case_over_six(a, b, argc);
	a = a->last_node;
	//print_stack(a, b);
	return (0);
}