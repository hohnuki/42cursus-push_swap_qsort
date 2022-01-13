#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*start_a;
	t_stack	*tmp;
	int	i;

	i = 1;
	a = ft_lstnew(NULL);
	b = ft_lstnew(NULL);
	start_a = a;
	while (i < argc)
	{
		tmp = ft_lstnew(argv[i]);
		tmp->prev = a;
		a->next = tmp;
		a = tmp;
		if ((i + 1) == argc)
		{
			a->next = start_a;
			start_a->prev = a;
		}
		i++;
	}
	if ((argc - 1) == 0)
		return (0);
	else if ((argc - 1) == 2)
		a = sort_case_two(a);
	else if ((argc - 1) == 3)
		a = sort_case_three(a);
	else if ((argc - 1) == 5)
		a = sort_case_five(a, b);
	else if ((argc - 1) == 6)
		a = sort_case_six(a, b);
	else
		a = sort_case_over_six(a, b, argc);
	print_stack(a, b);
	return (0);
}