#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	void			*content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(void *content);
void	command_sa(t_stack *a);
void	command_sb(t_stack *b);
void	command_ss(t_stack *a, t_stack *b);
t_stack	*command_ra(t_stack *a);
t_stack	*command_rb(t_stack *b);
void	command_rr(t_stack *a, t_stack *b);
t_stack	*command_rra(t_stack *a);
t_stack	*command_rrb(t_stack *b);
t_stack	*command_pa(t_stack *a, t_stack *b);
t_stack	*command_pb(t_stack *a, t_stack *b);
t_stack	*sort_case_three(t_stack *a);


#endif