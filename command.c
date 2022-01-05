#include "push_swap.h"

void	command_sa(t_stack *a)
{
	int	tmp;
	int	tmp_prev;

	tmp = 0;
	tmp = a->number;
	a = a->prev;
	tmp_prev = a->number;
	a->number = tmp;
	a = a->next;
	a->number = tmp_prev;
}

//void	command_ra(t_stack *a)
//{
//
//}

t_stack	*ft_lstnew(int n)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->number = n;
	ptr->next = NULL;
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*start;
	t_stack	*end;
	int	i;
	int	argc_value;

	start = ft_lstnew(0);
	end = ft_lstnew(0);
	i = 1;
	argc_value = argc;
	start->prev = end;
	end->next = start;
	while (i < argc)
	{
		a = ft_lstnew(atoi(argv[i]));
		if (i == 1)
			a->prev = start;
		else
			a->prev = tmp;
		tmp = a;
		i++;
	}
	end->prev = tmp;

	while (argc - 1 > 0)
	{
		if (argc == i)
			a->next = end;
		else
			a->next = tmp;
		tmp = a;
		a = a->prev;
		argc--;
	}
	a->next = tmp;
	a = a->prev;
	a = a->prev;

	command_sa(a);

	printf("--------------------\n");
	for (int i = 0; i < argc_value; i++)
	{
		printf("ptr->number reverse = %d \n", a->number);
		a = a->prev;
	}

}