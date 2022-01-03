#include "list.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (1)
	{
		if (lst->next == NULL)
			return (count);
		lst = lst->next;
		count++;
	}
}