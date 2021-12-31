#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void init(stack *p){
	p->top = -1;
	for(int i=0; i<max; i++)
		p->date[i] = 0;
}

void push(stack *p){
	int v;
	
	if(p->top >= max-1){
		printf("これ以上積めません\n");
	}else{
		printf("pushする値を入力してください:");
		scanf("%d",&v);
		
		p->top++;
		p->date[p->top] = v;
	}
}

void pop(stack *p){
	if(p->top <= -1)
		printf("これ以上取り出せません\n");
	else{
		p->date[p->top] = 0;
		p->top--;
	}
}

void show(stack *p){
	printf("stack:");
	for(int i=p->top; i >= 0; i--)
		printf("%3d",p->date[i]);
	
	printf("\n\n");
}

int main(int argc, const char **argv)
{
	int		sw;
	int		i;
	stack	*a;
	
	i = 1;
	while (i < argc)
	{
		a->number = arg[i];
		a->next = (stack *)argv[i + 1];
		a->prev = (stack *)argv[i - 1];
		i++;
	}
	
	while (i < argc)
	{
		printf("%ld \n", a->number);
		a->next = (stack *)argv[i + 1];
		i++;
	}
//	while(1)
//	{
//		printf("何を行いますか？\n");
//		printf("0:push 1:pop 2:exit\n:");
//		scanf("%d",&sw);
//		switch(sw)
//		{
//			case 0: push(&a);
//				show(&a);
//				break;
//			case 1: pop(&a);
//				show(&a);
//				break;
//			case 2:
//				exit(0);
//				break;
//		}
//	}
}

//int main(int argc, char **argv)
//{
//	t_list	a;
//	t_list	b;
//	size_t	i;
//
//	a = (t_list)malloc(sizeof(int) * argc);
//	b = (t_list)malloc(sizeof(int) * argc);
//	while ()
//}