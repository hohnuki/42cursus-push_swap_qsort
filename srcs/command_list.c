#include "../includes/push_swap.h"

void	cmd_sa(t_stack *a, t_list_info *list_info)
{
	char	*tmp;

	printf("sa\n");
	a = list_info->a_last_node;
	tmp = a->content;
	a->content = (a->prev)->content;
	(a->prev)->content = tmp;
}

void	cmd_sb(t_stack *b, t_list_info *list_info)
{
	char	*tmp;

	printf("sb\n");
	b = list_info->a_last_node;
	tmp = b->content;
	b->content = (b->prev)->content;
	(b->prev)->content = tmp;
}

void	cmd_ss(t_stack *a, t_stack *b, t_list_info *list_info)
{
	printf("ss\n");
	cmd_sa(a, list_info);
	cmd_sb(b, list_info);
}

void	cmd_ra(t_stack *a, t_list_info *list_info)
{
	t_stack	*free_address;
	t_stack	*new;

	printf("ra\n");
	a = list_info->a_last_node;
	list_info->a_last_node = a->prev;
	free_address = a;
	new = ft_lstnew(a->content);
	if (new == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	(a->prev)->next = a->next;
	(a->next)->prev = a->prev;
	((a->next)->next)->prev = new;
	new->next = (a->next)->next;
	(a->next)->next = new;
	new->prev = (a->next);
	free (free_address);
}

void	cmd_rb(t_stack *b, t_list_info *list_info)
{
	t_stack	*free_address;
	t_stack	*new;

	printf("rb\n");
	b = list_info->b_last_node;
	list_info->b_last_node = b->prev;
	free_address = b;
	new = ft_lstnew(b->content);
	if (new == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	(b->prev)->next = b->next;
	(b->next)->prev = b->prev;
	((b->next)->next)->prev = new;
	new->next = (b->next)->next;
	(b->next)->next = new;
	new->prev = (b->next);
	free (free_address);
}

void	cmd_rr(t_stack *a, t_stack *b, t_list_info *list_info)
{
	printf("rr\n");
	cmd_ra(a, list_info);
	cmd_rb(b, list_info);
}

void	cmd_rra(t_stack *a, t_list_info *list_info)
{
	t_stack	*free_address;
	t_stack	*new;

	printf("rra\n");
	a = list_info->a_last_node;
	free_address = (a->next)->next;
	new = ft_lstnew(((a->next)->next)->content);
	if (new == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	list_info->a_last_node = new;
	new->prev = a;
	new->next = a->next;
	(a->next)->prev = new;
	a->next = new;
	(new->next)->next = ((new->next)->next)->next;
	((new->next)->next)->prev = new->next;
	free (free_address);
}

void	cmd_rrb(t_stack *b, t_list_info *list_info) {
	t_stack *free_address;
	t_stack *new;

	printf("rrb\n");
	b = list_info->a_last_node;
	free_address = (b->next)->next;
	new = ft_lstnew(((b->next)->next)->content);
	if (new == NULL) {
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	list_info->a_last_node = new;
	new->prev = b;
	new->next = b->next;
	(b->next)->prev = new;
	b->next = new;
	(new->next)->next = ((new->next)->next)->next;
	((new->next)->next)->prev = new->next;
	free(free_address);
}

void	cmd_rrr(t_stack *a, t_stack *b, t_list_info *list_info)
{
	printf("rra\n");
	cmd_rra(a, list_info);
	cmd_rrb(b, list_info);
}

void	cmd_pa(t_stack *a, t_stack *b, t_list_info *list_info)
{
	printf("pa\n");
	b = list_info->b_last_node;
	a = list_info->a_last_node;
	list_info->b_last_node = b->prev;
	list_info->a_last_node = b;
	(b->prev)->next = b->next;
	(b->next)->prev = b->prev;
	b->next = a->next;
	(a->next)->prev = b;
	a->next = b;
	b->prev = a;
}

void	cmd_pb(t_stack *a, t_stack *b, t_list_info *list_info)
{
	printf("pb\n");
	a = list_info->a_last_node;
	b = list_info->b_last_node;
	list_info->a_last_node = a->prev;
	list_info->b_last_node = a;
	(a->prev)->next = a->next;
	(a->next)->prev = a->prev;
	a->next = b->next;
	(b->next)->prev = a;
	b->next = a;
	a->prev = b;
}