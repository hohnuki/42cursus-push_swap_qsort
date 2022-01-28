#include "../includes/push_swap.h"

//static char	*get_pivot(t_stack *stack, int argc)
//{
//	char	*pivot;
//	int		half_argc;
//
//	half_argc = argc / 2;
//	while (half_argc > 0)
//	{
//		stack = stack->prev;
//		half_argc--;
//	}
//	pivot = stack->content;
//	return (pivot);
//}
//
//t_stack	*sort_case_over_six(t_stack *a, t_stack *b, int argc)
//{
//	char	*pivot;
//	int		i;
//
//	pivot = get_pivot(a, argc);
//	printf("pivot = %s \n", pivot);
//	i = 0;
//	while (i < argc - 1)
//	{
//		if (atoi(a->content) < atoi(pivot))
//		{
//			a = cmd_pb(a, b);
//			b = b->next;
//		}
//		else
//			a = cmd_ra(a);
//		i++;
//	}
//	return (a);
//}
//
//1 2 3 4 5 6 7 8 9 10
//
//3 4 2 9 5 7 8 6 3 4 A
//                    B
//
//9 5 7 8 6           A
//4 3 2 4 3           B
//
//3 2 3|9 5 7 8 6     A   3 3 2|9 5 7 8 6
//4 4                 B
//
//4 4 3 3 2|9 5 7 8 6 A
//                    B
//
//4 4 3 3 2|9 7 8     A
//6 5                 B 5 6
//
//6 5 4 4 3 3 2|9 7 8 A
//					B
//
//6 5 4 4 3 3 2|9 8   A
//7                   B
//
//7 6 5 4 4 3 3 2|9 8 A >> 9 8 7 6 5 4 4 3 3 2 (fin)
//                    B
