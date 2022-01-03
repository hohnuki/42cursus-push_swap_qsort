#include "stdio.h"
#include "stdlib.h"

#define MAX 5

typedef	struct s_stack
{
	int date[MAX];
	int top;
}	t_stack;

void	stack_init(t_stack *ptr)
{
	ptr->top = -1;
	for(int i = 0; i < MAX; i++)
		ptr->date[i] = 0;
}

void	stack_push(t_stack *ptr)
{
	int value;

	if (ptr->top >= MAX-1)
		printf("これ以上積めません\n");
	else
	{
		printf("pushする値を入力してください:");
		scanf("%d",&value);
		ptr->top++;
		ptr->date[ptr->top] = value;
	}
}

void	stack_pop(t_stack *ptr)
{
	if(ptr->top <= -1)
		printf("これ以上取り出せません\n");
	else
	{
		ptr->date[ptr->top] = 0;
		ptr->top--;
	}
}

void	stack_show(t_stack *ptr)
{
	printf("stack:");
	for(int i = ptr->top; i >= 0; i--)
		printf("%3d", ptr->date[i]);
	printf("\n\n");
}

int	main(void)
{
	t_stack	s;
	int	s_num;

	stack_init(&s);
	s_num = 0;
	while(1)
	{
		printf("何を行いますか？\n");
		printf("0:push 1:pop 2:exit\n:");
		scanf("%d", &s_num);
		switch (s_num)
		{
			case 0:
				stack_push(&s);
				stack_show(&s);
				break;

			case 1:
				stack_pop(&s);
				stack_show(&s);
				break;

			case 2:
				exit(0);
				break;
		}
	}
}