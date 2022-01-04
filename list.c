#include "push_swap.h"

//t_stack	*head = NULL;
//
//void	init();
//void	display(void);
//void 	release(void);
//
//int push(int n)
//{
//	t_stack	*s = (t_stack*)malloc(sizeof(t_stack));
//	if (s == NULL)
//		return (0);
//	s->data = n;
//	s->next = head;
//	head = s;
//	return (1);
//}
//
//int main(int argc, char **argv)
//{
//	int	i;
//
//	i = 1;
//	init();
//	while (i < argc)
//	{
//		push(atoi(argv[i]));
//		i++;
//	}
//	display();
//	release();
//	return (0);
//}
//
//void display(void)
//{
//	printf("----\n");
//	for (t_stack *s = head; s != NULL; s = s->next)
//		printf("%d\n", s->data);
//	printf("----\n");
//}
//
//void release(void)
//{
//	t_stack	*s = head;
//
//	while (s != NULL)
//	{
//		t_stack	*tmp = s->next;
//		free(s);
//		s = tmp;
//	}
//}
//
//void init()
//{
//	if (head != NULL)
//		release();
//	head = NULL;
//}
//
//int pop(int *n)
//{
//	t_stack	*s = head;
//
//	if (s == NULL)
//		return 0; // error
//	head = s->next;
//	*n = s->data;
//	free(s);
//	return 1;  // success
//}
//
//void delete(void)
//{
//	int n = 0;
//	if (pop(&n) == 1)
//		printf("%d has just deleted \n", n);
//	else
//		printf("--- error\n");
//}


t_stack	*ft_lstnew(int number)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->data = number;
	ptr->next = NULL;
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_stack	*ptr;
	t_stack	*start;
	int		i;

	i = 1;
	start = ft_lstnew(atoi(argv[i]));
	i++;
	while (i < argc)
	{
		ptr = ft_lstnew(atoi(argv[i]));
//		if (i == argc)
//			ptr->next = start;
//		else
		ptr->next = (t_stack *)argv[i + 1];
//		if (i == 2)
//			ptr->prev = start;
//		else
//			ptr->prev = (t_stack *)argv[i - 1];
		i++;
	}

	i = 1;
	ptr = sta
	printf("--------------\n");
	while (i < argc)
	{
		printf("%d \n", ptr->data);
		ptr = ptr->prev;
		i++;
	}
	printf("--------------\n");
}