#include "list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)//*lstが指すノードから始まる線形リストの最後尾に、新しいノード(*new)を付け加える関数
{
	if (lst == NULL || new == NULL)
		return ;
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
}

int	main(void)
{
	t_list	*list = ft_lstnew(strdup("OK!"));
	t_list	*next = ft_lstnew(strdup("NG!"));
	ft_lstadd_back(&list, next);

	printf("%s\n", (char *)list->content);
}