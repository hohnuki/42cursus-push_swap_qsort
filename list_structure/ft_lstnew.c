#include "list.h"

t_list	*ft_lstnew(void *content)//新しいノード構造体のためのメモリをヒープ領域に割り当てるための関数である.
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));//sizeof(t_list)は，ノード構造体のメモリサイズである．その容量のメモリを malloc で割り当てる。
	if (ptr == NULL)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

//int main(void)
//{
//	char	*data = "hello, i'm a data";
//	t_list	*list = ft_lstnew(data);
//
//	printf("list->content = %s \n", (char *)list->content);
//}