#include "push_swap.h"

t_stack	*sort_case_over_six(t_stack *a, t_stack *b)
{

}

1 2 3 4 5 6 7 8 9 10 aaaaaa

3 4 2 9 5 7 8 6 3 4 A
                    B

9 5 7 8 6           A
4 3 2 4 3           B

3 2 3|9 5 7 8 6     A   3 3 2|9 5 7 8 6
4 4                 B

4 4 3 3 2|9 5 7 8 6 A
                    B

4 4 3 3 2|9 7 8     A
6 5                 B 5 6

6 5 4 4 3 3 2|9 7 8 A
					B

6 5 4 4 3 3 2|9 8   A
7                   B

7 6 5 4 4 3 3 2|9 8 A >> 9 8 7 6 5 4 4 3 3 2 (fin)
                    B
