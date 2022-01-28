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

	printf("ra\n");
	a = a->last_node;
	a->last_node = a->prev;
	(a->next)->prev = a->prev;
	(a->prev)->next = a->next;
	a->prev = a->next;
	a->next = (a->next)->next;
	(a->next)->prev = a;
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
	printf("rra\n");
	a = a->last_node;
	a->last_node = (a->next)->next;
	a->next = (a->next)->next;
	(a->next)->next = a->next;
	((a->next)->next)->prev = a;
	(a->prev)->prev = a->next;
	(a->next)->next = a->prev;
}

void	cmd_rrb(t_stack *b)
{
	printf("rra\n");
	b = b->last_node;
	b->last_node = (b->next)->next;
	b->next = (b->next)->next;
	(b->next)->next = b->next;
	((b->next)->next)->prev = b;
	(b->prev)->prev = b->next;
	(b->next)->next = b->prev;
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