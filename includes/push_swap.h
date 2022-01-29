#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "unistd.h"
#define LOOP_SIZE 10

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_list_info
{
	t_stack	*a_last_node;
	t_stack	*b_last_node;
}	t_list_info;


t_stack		*ft_lstnew(void *content);
int			ft_lstsize_rev(t_stack *lst);
void		ft_putendl_fd(char *s, int fd);
long long	ps_atoi(char *str);
void		cmd_sa(t_stack *a, t_list_info *list_info);
//void		cmd_sb(t_stack *b);
//void		cmd_ss(t_stack *a, t_stack *b);
void		cmd_ra(t_stack *a, t_list_info *list_info);
//void		cmd_rb(t_stack *b);
//void		cmd_rr(t_stack *a, t_stack *b);
void		cmd_rra(t_stack *a, t_list_info *list_info);
//void		cmd_rrb(t_stack *b);
//t_stack		*cmd_pa(t_stack *a, t_stack *b);
//t_stack		*cmd_pb(t_stack *a, t_stack *b);
void		print_stack(t_stack *a, t_stack *b);
void		sort_case_two(t_stack *a, t_list_info *list_info);
void		sort_case_three(t_stack *a, t_list_info *list_info);
void		sort_case_five(t_stack *a, t_stack *b, t_list_info *list_info);
t_stack		*sort_case_six(t_stack *a, t_stack *b);
t_stack		*sort_case_over_six(t_stack *a, t_stack *b, int argc);

#endif