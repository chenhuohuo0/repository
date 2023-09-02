#define _CRT_SECURE_NO_WARNINGS
//link_stack.c
#include "link_stack.h"

//³õÊ¼»¯
stack* init_stack(stack** top)
{
	*top = NULL;
	return *top;
}

//ÅÐÕ»¿Õ
int stack_is_empty(stack* top)
{
	if (!top)
	{
		return 1;
	}
	return 0;
}

//Ñ¹Õ»
int push_stack(stack** top, datatype x)
{
	stack* p = (stack*)malloc(sizeof(stack));
	if (!p)
	{
		perror("ÄÚ´æÒç³ö\n");
		return 0;
	}
	else
	{
		p->data = x;
		p->next = *top;
		*top = p;
	}
}

//³öÕ»
int pop_stack(stack** top, datatype* x)
{
	if ((*top) == NULL)
	{
		printf("¿ÕÕ»\n");
		return 0;
	}
	stack* p = *top;
	*x = (*top)->data;
	*top = p->next;
	free(p);
	return 1;
}

//È¡Õ»¶¥ÔªËØ
int get_stack_top(stack* top, datatype* x)
{
	if (!top)
	{
		printf("¿ÕÕ»\n");
		return 0;
	}
	*x = top->data;
	return 1;
}

//±éÀú
void print_stack(stack* top)
{
	stack* p = top;
	printf("top ->");
	while (p)
	{
		printf("%d ->", p->data);
		p = p->next;
	}
	printf(" NULL\n");
}

//Ïú»Ù
void destory_stack(stack** top)
{
	stack* p = *top;
	stack* q = p;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*top = NULL;
}