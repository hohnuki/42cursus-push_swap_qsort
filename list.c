#include "push_swap.h"

void	command_sa(t_stack *a)
{
	int	tmp;
	int	tmp_prev;

	tmp = a->number;
	a = a->prev;
	tmp_prev = a->number;
	a->number = tmp;
	a = a->next;
	a->number = tmp_prev;
}

void	command_ra(t_stack *a)
{
	int	tmp;
	int tmp_prev;

	tmp = a->number;
	a = a->next;
	a = a->next;
	tmp_prev = a->number;
	a->number = tmp;
	a = a->prev;
	a = a->prev;
	a->number = tmp_prev;
}

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
	t_stack	*start;
	int	i;

	i = 1;
	start = ft_lstnew(0);
	while (i < argc)
	{
		a = ft_lstnew(atoi(argv[i]));
		if (i == 1)
			start->next = a;
		else
			tmp->next = a;
		if (i == 1)
			a->prev = start;
		else
			a->prev = tmp;
		tmp = a;
		i++;
	}
	a->next = start;
	start->prev = tmp;

//	printf("--------------------\n");
//	for (int j = 0; j < 10; j++)
//	{
//		printf("ptr->number =         %d \n", a->number);
//		printf("flag = %s \n", a->flag);
//		a = a->next;
//	}
	printf("--------------------\n");
	for (int j = 0; j < 10; j++)
	{
		printf("ptr->number reverse = %d \n", a->number);
		a = a->prev;
	}
}