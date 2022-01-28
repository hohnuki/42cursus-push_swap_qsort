#include "../includes/push_swap.h"

t_stack	*ft_lstnew(void *content)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

int	ft_lstsize_rev(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst->content != NULL)
	{
		lst = lst->prev;
		i++;
	}
	return (i);
}

//void	ft_lstadd_back(t_list **lst, t_list *new)//*lstが指すノードから始まる線形リストの最後尾に、新しいノード(*new)を付け加える関数
//{
//	if (lst == NULL || new == NULL)
//		return ;
//	while (*lst != NULL)
//		lst = &(*lst)->next;
//	*lst = new;
//}

//void	ft_lstadd_front(t_list **lst, t_list *new)//*lstが指すノードから始まる線形リストの先頭に、新しいノード(*new)を付け加える関数。
//{
//	if (lst == NULL || new == NULL)
//		return ;
//	*lst = new;
//	new->next = *lst;
//}

//t_list	*ft_lstlast(t_list *lst)
//{
//	if (lst == NULL)
//		return (NULL);
//	while (1)
//	{
//		if (lst->next == NULL)
//			return (lst);
//		lst = lst->next;
//	}
//}