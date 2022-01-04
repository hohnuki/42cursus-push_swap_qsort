#include "push_swap.h"

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
	t_stack	*ptr;
	t_stack	*tmp;
	t_stack	*start;
	t_stack	*end;
	int	i;

	start = ft_lstnew(0);
	end = ft_lstnew(0);
	i = 1;
	start->prev = end;
	end->next = start;
	while (i < argc)
	{
		ptr = ft_lstnew(atoi(argv[i]));
		if (i == 1)
			ptr->prev = start;
		else
			ptr->prev = tmp;
		tmp = ptr;
		i++;
	}
	end->prev = tmp;

	while (argc - 1 > 0)
	{
		if (argc == i)
			ptr->next = end;
		else
			ptr->next = tmp;
		tmp = ptr;
		ptr = ptr->prev;
		argc--;
	}
	ptr->next = tmp;

	printf("--------------------\n");
	for (int i = 0; i < 20; i++)
	{
		printf("ptr->number = %d \n", ptr->number);
		ptr = ptr->next;
	}
	printf("--------------------\n");
	for (int i = 0; i < 20; i++)
	{
		printf("ptr->number reverse = %d \n", ptr->number);
		ptr = ptr->prev;
	}
}