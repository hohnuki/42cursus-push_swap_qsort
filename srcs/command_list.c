#include "../includes/push_swap.h"

void	cmd_sa(t_stack *a)
{
	char	*tmp;

	printf("sa\n");
	tmp = a->content;
	a->content = (a->prev)->content;
	(a->prev)->content = tmp;
}

void	cmd_sb(t_stack *b)
{
	char	*tmp;

	printf("sb\n");
	tmp = b->content;
	b->content = (b->prev)->content;
	(b->prev)->content = tmp;
}

void	cmd_ss(t_stack *a, t_stack *b)
{
	printf("ss\n");
	cmd_sa(a);
	cmd_sb(b);
}

void	cmd_ra(t_stack *a)
{
	t_stack	*tmp_adress;
	t_stack	*free_address;
	t_stack	*new;

	printf("ra\n");
	tmp_adress = a->last_node;
	a = tmp_adress;
	printf("\x1b[36m[%p]\n\033[m", tmp_adress);
	printf("\x1b[36m[%p]\n\033[m", a->last_node);

	for (int j = 0; j < LOOP_SIZE; j++)
	{
		printf("a->content reverse = %s \n", (char *)a->content);
		a = a->prev;
	}
	for (int j = 0; j < LOOP_SIZE / 2; j++)
	{
		printf("a->content =         %s \n", (char *)a->content);
		a = a->next;
	}
	a = tmp_adress;
	a->last_node = a->prev;
	free_address = a;
	new = ft_lstnew(a->content);
	if (new == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	new->last_node = tmp_adress;
	(a->prev)->next = a->next;
	(a->next)->prev = a->prev;
	((a->next)->next)->prev = new;
	new->next = (a->next)->next;
	(a->next)->next = new;
	new->prev = (a->next);
	free (free_address);
}

void	cmd_rb(t_stack *b)
{
	b = b->last_node;
	b->last_node = b->prev;
	(b->next)->prev = b->prev;
	(b->prev)->next = b->next;
	b->prev = b->next;
	b->next = (b->next)->next;
	(b->next)->prev = b;
}

void	cmd_rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	cmd_ra(a);
	cmd_rb(b);
}

void	cmd_rra(t_stack *a)
{
	t_stack	*free_address;
	t_stack	*new;

	printf("rra\n");
	a = a->last_node;
	free_address = (a->next)->next;
	new = ft_lstnew(((a->next)->next)->content);
	if (new == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	a->last_node = new;
	new->prev = a;
	new->next = a->next;
	(a->next)->prev = new;
	a->next = new;
	(new->next)->next = ((new->next)->next)->next;
	((new->next)->next)->prev = new->next;
	free (free_address);
}

void	cmd_rrb(t_stack *b)
{
	t_stack	*free_address;
	t_stack	*new;

	printf("rrb\n");
	b = b->last_node;
	free_address = (b->next)->next;
	new = ft_lstnew(((b->next)->next)->content);
	if (new == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	b->last_node = new;
	new->prev = b;
	new->next = b->next;
	(b->next)->prev = new;
	b->next = new;
	(new->next)->next = ((new->next)->next)->next;
	((new->next)->next)->prev = new->next;
	free (free_address);
}

t_stack	*cmd_pa(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*start_a;

	printf("pa\n");
	tmp = b;
	start_a = a;
	while (start_a->content != NULL)
		start_a = start_a->prev;
	(b->prev)->next = b->next;
	(b->next)->prev = b->prev;
	b = b->prev;
	a->next = tmp;
	tmp->prev = a;
	tmp->next = start_a;
	start_a->prev = tmp;
	return (b);
}

t_stack	*cmd_pb(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*start_b;

	printf("pb\n");
	tmp = a;
	start_b = b;
	while (start_b->content != NULL)
		start_b = start_b->prev;
	(a->prev)->next = a->next;
	(a->next)->prev = a->prev;
	a = a->prev;
	b->next = tmp;
	tmp->prev = b;
	tmp->next = start_b;
	start_b->prev = tmp;
	return (a);
}