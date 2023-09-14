#define _CRT_SECURE_NO_WARNINGS
#include "seqstack.h"
int main()
{
	stack* H = init_stack();
	int x;
	//int ret;
	//ret = stack_is_empty(H);
	//printf("%d\n", ret);
	push_stack(H, 3);
	push_stack(H, 2);
	push_stack(H, 1);
	push_stack(H, 4);
	//pop_stack(H, &x);
	//get_stack_top(H, &x);
	//printf("%d\n", x);
	print_stack(H);


	destory_stack(&H);
}