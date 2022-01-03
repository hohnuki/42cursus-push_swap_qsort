#include "list.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (1)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
}

int main(void)
{
	t_list	*list;
	t_list	*actual;
	t_list	*expected;

	list = ft_lstnew(strdup("1"));
	list->next = ft_lstnew(strdup("2"));
	list->next->next = ft_lstnew(strdup("3"));
	actual = list->next->next;
	expected = ft_lstlast(list);

	printf("actual = %c \n", (char)actual);
	printf("expected = %c \n", (char)expected);
}