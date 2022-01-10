#include "push_swap.h"

void	cmd_sa(t_stack *a)
{
	char	*tmp;
	char	*tmp_prev;

	printf("sa\n");
	tmp = a->content;
	a = a->prev;
	tmp_prev = a->content;
	a->content = tmp;
	a = a->next;
	a->content = tmp_prev;
}

void	cmd_sb(t_stack *b)
{
	char	*tmp;
	char	*tmp_prev;

	printf("sb\n");
	tmp = b->content;
	b = b->prev;
	tmp_prev = b->content;
	b->content = tmp;
	b = b->next;
	b->content = tmp_prev;
}

void	cmd_ss(t_stack *a, t_stack *b)
{
	printf("ss\n");
	cmd_sa(a);
	cmd_sb(b);
}

t_stack	*cmd_ra(t_stack *a)
{
	char	*tmp_content;
	t_stack	*free_address;
	t_stack	*new;

	printf("ra\n");
	tmp_content = a->content;
	free_address = a;
	new = ft_lstnew(tmp_content);
	(a->prev)->next = a->next;
	(a->next)->prev = a->prev;
	((a->next)->next)->prev = new;
	new->next = (a->next)->next;
	(a->next)->next = new;
	new->prev = (a->next);
	a = a->prev;
	free (free_address);
	return (a);
}

t_stack	*cmd_rb(t_stack *b)
{
	char	*tmp_content;
	t_stack	*free_address;
	t_stack	*new;

	printf("rb\n");
	tmp_content = b->content;
	free_address = b;
	new = ft_lstnew(tmp_content);
	(b->prev)->next = b->next;
	(b->next)->prev = b->prev;
	((b->next)->next)->prev = new;
	new->next = (b->next)->next;
	(b->next)->next = new;
	new->prev = (b->next);
	b = b->prev;
	free (free_address);
	return (b);
}

void	cmd_rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	cmd_ra(a);
	cmd_rb(b);
}

t_stack	*cmd_rra(t_stack *a)
{
	char	*tmp_content;
	t_stack	*free_address;
	t_stack	*new;

	printf("rra\n");
	tmp_content = ((a->next)->next)->content;
	free_address = (a->next)->next;
	new = ft_lstnew(tmp_content);
	new->prev = a;
	new->next = a->next;
	(a->next)->prev = new;
	a->next = new;
	(new->next)->next = ((new->next)->next)->next;
	((new->next)->next)->prev = new->next;
	a = new;
	free (free_address);
	return (a);
}

t_stack	*cmd_rrb(t_stack *b)
{
	char	*tmp_content;
	t_stack	*free_address;
	t_stack	*new;

	printf("rrb\n");
	tmp_content = ((b->next)->next)->content;
	free_address = (b->next)->next;
	new = ft_lstnew(tmp_content);
	new->prev = b;
	new->next = b->next;
	(b->next)->prev = new;
	b->next = new;
	(new->next)->next = ((new->next)->next)->next;
	((new->next)->next)->prev = new->next;
	b = new;
	free (free_address);
	return (b);
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