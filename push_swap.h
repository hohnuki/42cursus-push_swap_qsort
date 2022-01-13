#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define LOOP_SIZE 7

typedef struct s_stack
{
	struct s_stack	*prev;
	void			*content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(void *content);
int		ft_lstsize_rev(t_stack *lst);
void	cmd_sa(t_stack *a);
void	cmd_sb(t_stack *b);
void	cmd_ss(t_stack *a, t_stack *b);
t_stack	*cmd_ra(t_stack *a);
t_stack	*cmd_rb(t_stack *b);
void	cmd_rr(t_stack *a, t_stack *b);
t_stack	*cmd_rra(t_stack *a);
t_stack	*cmd_rrb(t_stack *b);
t_stack	*cmd_pa(t_stack *a, t_stack *b);
t_stack	*cmd_pb(t_stack *a, t_stack *b);
void	print_stack(t_stack *a, t_stack *b);
t_stack	*sort_case_two(t_stack *a);
t_stack	*sort_case_three(t_stack *a);
t_stack	*sort_case_five(t_stack *a, t_stack *b);
t_stack	*sort_case_six(t_stack *a, t_stack *b);
t_stack	*sort_case_over_six(t_stack *a, t_stack *b, int argc);

#endif