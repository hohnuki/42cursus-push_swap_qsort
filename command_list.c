#include "push_swap.h"

void	command_sa(t_stack *a)
{
	char	*tmp;
	char	*tmp_prev;

	tmp = a->content;
	a = a->prev;
	tmp_prev = a->content;
	a->content = tmp;
	a = a->next;
	a->content = tmp_prev;
}

void	command_sb(t_stack *b)
{
	char	*tmp;
	char	*tmp_prev;

	tmp = b->content;
	b = b->prev;
	tmp_prev = b->content;
	b->content = tmp;
	b = b->next;
	b->content = tmp_prev;
}

void	command_ss(t_stack *a, t_stack *b)
{
	command_sa(a);
	command_sb(b);
}

t_stack	*command_ra(t_stack *a)
{
	char	*tmp_content;
	t_stack	*free_address;
	t_stack	*new;

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

t_stack	*command_rb(t_stack *b)
{
	char	*tmp_content;
	t_stack	*free_address;
	t_stack	*new;

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

void	command_rr(t_stack *a, t_stack *b)
{
	command_ra(a);
	command_rb(b);
}

t_stack	*command_rra(t_stack *a)//最初(startの次)のスタックをフリーしていない。
{
	char	*tmp;
	char	*tmp_prev;

	command_sa(a);
	tmp = a->content;
	a = (a->next)->next;
	tmp_prev = a->content;
	a->content = tmp;
	a = (a->prev)->prev;
	a->content = tmp_prev;
	return (a);
}

t_stack	*command_rrb(t_stack *b)
{
	char	*tmp;
	char	*tmp_prev;

	command_sa(b);
	tmp = b->content;
	b = (b->next)->next;
	tmp_prev = b->content;
	b->content = tmp;
	b = (b->prev)->prev;
	b->content = tmp_prev;
	return (b);
}

t_stack	*command_pa(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*start_a;

	tmp = b;
	start_a = a;
	while (start_a->content != NULL)
		start_a = start_a->prev;
	(b->prev)->next = b->next;
	(b->next)->prev = b->prev;
	b = b->prev;
	a->next = tmp;
	tmp->prev = b;
	tmp->next = start_a;
	start_a->prev = tmp;
	return (b);
}

t_stack	*command_pb(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*start_b;

	tmp = a;
	start_b = b;
	while(start_b->content != NULL)
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