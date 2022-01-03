#include "list.h"

void	ft_lstadd_front(t_list **lst, t_list *new)//*lstが指すノードから始まる線形リストの先頭に、新しいノード(*new)を付け加える関数。
{
	if (lst == NULL || new == NULL)
		return ;
	*lst = new;
	new->next = *lst;
}

int	main(void)
{
	t_list	*list = ft_lstnew(strdup("NG!"));
	t_list	*next = ft_lstnew(strdup("OK!"));
	ft_lstadd_front(&list, next);

	printf("%s\n", (char *)list->content);
}