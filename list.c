#include "push_swap.h"

t_stack	*ft_lstnew(int num)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->number = num;
	ptr->next = NULL;
	return ptr;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*start_a;
	t_stack	*start_b;
	int	i;
	int argc_tmp;

	i = 1;
	argc_tmp = argc;
	start_b = ft_lstnew(0);
	start_a = ft_lstnew(0);

	while (i < argc)
	{
		a = ft_lstnew(atoi(argv[i]));
		if (i == 1)
			start_a->next = a;
		else
			tmp->next = a;
		if (i == 1)
			a->prev = start_a;
		else
			a->prev = tmp;
		tmp = a;
		i++;
	}
	a->next = start_a;
	start_a->prev = tmp;

	command_pb(a, start_b);
//	printf("--------------------\n");
//	for (int j = 0; j < 10; j++)
//	{
//		printf("ptr->number =         %d \n", a->number);
//		printf("flag = %s \n", a->flag);
//		a = a->next;
//	}
	printf("--------------------\n");
	for (int j = 0; j < argc_tmp - 1; j++)
	{
		printf("ptr->number reverse = %d \n", a->number);
		a = a->prev;
	}
	printf("--------------------\n");
}