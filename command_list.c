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

void	command_sb(t_stack *b)
{
	int	tmp;
	int	tmp_prev;

	tmp = b->number;
	b = b->prev;
	tmp_prev = b->number;
	b->number = tmp;
	b = b->next;
	b->number = tmp_prev;
}

void	command_ss(t_stack *a, t_stack *b)
{
	command_sa(a);
	command_sb(b);
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

void	command_rb(t_stack *b)
{
	int	tmp;
	int tmp_prev;

	tmp = b->number;
	b = b->next;
	b = b->next;
	tmp_prev = b->number;
	b->number = tmp;
	b = b->prev;
	b = b->prev;
	b->number = tmp_prev;
}

void	command_rr(t_stack *a, t_stack *b)
{
	command_ra(a);
	command_rb(b);
}

t_stack	*command_rra(t_stack *a)//最初(startの次)のスタックをフリーしていない。
{
	t_stack	*next_address;
	t_stack	*prev_address;
	t_stack	*new;
	int	tmp;

	a = a->next;
	prev_address = a;
	a = a->next;
	tmp = a->number;
	a = a->next;
	next_address = a;
	a->prev = prev_address;
	a = a->prev;
	a->next = next_address;
	a = a->prev;
	new = ft_lstnew(tmp);
	if (new == NULL)
		return (NULL);
	a->next = new;
	new->prev = a;
	new->next = prev_address;
	return (new);
}

t_stack	*command_rrb(t_stack *b)//最初(startの次)のスタックをフリーしていない。
{
	t_stack	*next_address;
	t_stack	*prev_address;
	t_stack	*new;
	int	tmp;

	b = b->next;
	prev_address = b;
	b = b->next;
	tmp = b->number;
	b = b->next;
	next_address = b;
	b->prev = prev_address;
	b = b->prev;
	b->next = next_address;
	b = b->prev;
	new = ft_lstnew(tmp);
	if (new == NULL)
		return (NULL);
	b->next = new;
	new->prev = b;
	new->next = prev_address;
	return (new);
}

t_stack	*command_pb(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->number;

}