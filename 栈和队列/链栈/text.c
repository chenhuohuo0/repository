#define _CRT_SECURE_NO_WARNINGS
//test.c
#include "link_stack.h"

int main()
{
	stack* top;
	init_stack(&top);

	push_stack(&top, 3);
	push_stack(&top, 2);
	push_stack(&top, 1);
	int x;
	pop_stack(&top, &x);

	printf("%d\n", x);
	get_stack_top(top, &x);
	printf("%d\n", x);
	print_stack(top);

	destory_stack(&top);
}